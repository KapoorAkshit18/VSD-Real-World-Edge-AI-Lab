#include <stdio.h>

#if defined(__has_include) && __has_include(<metal/cpu.h>)
#include <metal/cpu.h>
#include <metal/led.h>
#include <metal/button.h>
#include <metal/switch.h>
#endif

#include "scaler.h"
#include "svm_model.h"
#include "images.h"

#define RTC_FREQ 32768

/*
 * Custom float printer for embedded RISC-V newlib-nano
 */
void print_float(double val) {
    if (val < 0) {
        printf("-");
        val = -val;
    }
    int int_part = (int)val;
    int frac_part = (int)((val - (double)int_part) * 100.0);
    printf("%d.%02d", int_part, frac_part);
}

/*
 * Multi-Class Linear SVM Inference for MNIST (10 Classes x 784 Pixels)
 * Evaluates decision score for each digit (0 to 9) and returns argmax.
 */
int predict_digit(const float *image_pixels, double *out_confidence) {
    int best_digit = 0;
    double max_score = -1e9;

    for (int c = 0; c < NUM_CLASSES; c++) {
        double score = bias[c];

        for (int i = 0; i < NUM_FEATURES; i++) {
            // Standardize feature: z = (x - mean) / scale
            // If scale is near zero (e.g. border pixels that are always black), scaled pixel is 0.0
            double pixel = (double)image_pixels[i];
            double scaled_pixel = (scale[i] > 1e-6) ? ((pixel - mean[i]) / scale[i]) : 0.0;
            score += weights[c][i] * scaled_pixel;
        }

        if (score > max_score) {
            max_score = score;
            best_digit = c;
        }
    }

    if (out_confidence) {
        *out_confidence = max_score;
    }

    return best_digit;
}

int main(void) {
    printf("====================================================\n");
    printf(" VSD Edge AI Lab 3: MNIST Digit Classification\n");
    printf(" Target: SiFive FE310-G002 (16 KB SRAM, 4 MB Flash)\n");
    printf("====================================================\n\n");

    int correct = 0;

    for (int i = 0; i < NUM_TEST_IMAGES; i++) {
        double confidence = 0.0;
        int predicted = predict_digit(test_images[i], &confidence);
        int expected  = test_labels[i];

        printf("Sample %2d | True Label: %d | Predicted: %d | Score: ", i + 1, expected, predicted);
        print_float(confidence);

        if (predicted == expected) {
            printf(" | [PASS]\n");
            correct++;
        } else {
            printf(" | [MISMATCH]\n");
        }
    }

    printf("\n----------------------------------------------------\n");
    printf("Evaluation Complete: %d / %d Correct (", correct, NUM_TEST_IMAGES);
    print_float(((double)correct / (double)NUM_TEST_IMAGES) * 100.0);
    printf("%% Accuracy on embedded device)\n");
    printf("----------------------------------------------------\n");

    return 0;
}
