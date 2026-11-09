#include <stdio.h>

#if defined(__has_include) && __has_include(<metal/cpu.h>)
#include <metal/cpu.h>
#include <metal/led.h>
#include <metal/button.h>
#include <metal/switch.h>
#endif

#include "scaler.h"
#include "svm_model.h"

#define RTC_FREQ 32768

/*
 * Custom float printer for embedded RISC-V newlib-nano
 * Formats signed floating-point numbers without requiring float-enabled printf
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
 * Binary Classification Inference using Linear SVM (Social Network Ads)
 * Features:
 *   Index 0: Age (years)
 *   Index 1: Estimated Salary ($)
 */
int predict_purchase(double age, double salary, double *out_score) {
    // 1. Feature Standardization: z = (x - mean) / scale
    double age_scaled    = (age - mean[0]) / scale[0];
    double salary_scaled = (salary - mean[1]) / scale[1];

    // 2. SVM Hyperplane Decision: score = bias + (w0 * age_scaled) + (w1 * salary_scaled)
    double score = bias[0] + (weights[0][0] * age_scaled) + (weights[0][1] * salary_scaled);
    if (out_score) {
        *out_score = score;
    }

    // 3. Binary Decision: >= 0 -> Class 1 (Purchased), < 0 -> Class 0 (Not Purchased)
    return (score >= 0.0) ? 1 : 0;
}

// Test sample structure
typedef struct {
    double age;
    double salary;
    int actual_label;
    const char *description;
} TestCase_t;

int main(void) {
    printf("========================================\n");
    printf(" VSD Edge AI Lab 2: Linear SVM Inference\n");
    printf(" Target: SiFive FE310-G002 (RISC-V 320MHz)\n");
    printf("========================================\n\n");

    TestCase_t test_cases[] = {
        {19.0, 19000.0, 0, "Young user, low salary"},
        {35.0, 20000.0, 0, "Middle-aged, entry salary"},
        {47.0, 25000.0, 1, "Older user, moderate salary"},
        {45.0, 100000.0, 1, "Older user, high salary"},
        {26.0, 43000.0, 0, "Young user, average salary"}
    };

    int num_tests = sizeof(test_cases) / sizeof(test_cases[0]);
    int correct_predictions = 0;

    for (int i = 0; i < num_tests; i++) {
        double score = 0.0;
        int prediction = predict_purchase(test_cases[i].age, test_cases[i].salary, &score);

        printf("Test Case %d: %s\n", i + 1, test_cases[i].description);
        printf("  Inputs    : Age = ");
        print_float(test_cases[i].age);
        printf(" yrs, Salary = $");
        print_float(test_cases[i].salary);
        printf("\n");

        printf("  SVM Score : ");
        print_float(score);
        printf("\n");

        printf("  Prediction: %s (%d)\n", (prediction == 1) ? "PURCHASED" : "NOT PURCHASED", prediction);
        printf("  Actual    : %s (%d)\n", (test_cases[i].actual_label == 1) ? "PURCHASED" : "NOT PURCHASED", test_cases[i].actual_label);

        if (prediction == test_cases[i].actual_label) {
            printf("  Result    : [PASS]\n\n");
            correct_predictions++;
        } else {
            printf("  Result    : [MISMATCH]\n\n");
        }
    }

    printf("Summary: %d / %d test cases correctly classified.\n", correct_predictions, num_tests);

    return 0;
}
