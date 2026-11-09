#include <stdio.h>

#if defined(__has_include) && __has_include(<metal/cpu.h>)
#include <metal/cpu.h>
#include <metal/led.h>
#include <metal/button.h>
#include <metal/switch.h>
#endif

#define RTC_FREQ     32768

/*
 * Model Coefficients from Multiple Linear Regression (50_Startups.csv)
 *
 * Scikit-learn ColumnTransformer with OneHotEncoder prepended the 3 'State' dummy features:
 * Index 0: California
 * Index 1: Florida
 * Index 2: New York
 * Index 3: R&D Spend
 * Index 4: Administration Spend
 * Index 5: Marketing Spend
 */
#define W_STATE_CAL   8.66383692e+01f
#define W_STATE_FLA  -8.72645791e+02f
#define W_STATE_NY    7.86007422e+02f
#define W_RD_SPEND    7.73467193e-01f
#define W_ADMIN_SPEND 3.28845975e-02f
#define W_MKTG_SPEND  3.66100259e-02f

#define BIAS          42467.52924853278f   // intercept

// State enumeration for one-hot encoding
typedef enum {
    STATE_CALIFORNIA = 0,
    STATE_FLORIDA    = 1,
    STATE_NEW_YORK   = 2
} State_t;

// Full 6-feature prediction function
float predict_profit(float rd_spend, float admin_spend, float mktg_spend, State_t state) {
    float state_contrib = 0.0f;
    if (state == STATE_CALIFORNIA) {
        state_contrib = W_STATE_CAL;
    } else if (state == STATE_FLORIDA) {
        state_contrib = W_STATE_FLA;
    } else if (state == STATE_NEW_YORK) {
        state_contrib = W_STATE_NY;
    }

    return (W_RD_SPEND * rd_spend) +
           (W_ADMIN_SPEND * admin_spend) +
           (W_MKTG_SPEND * mktg_spend) +
           state_contrib +
           BIAS;
}

// 3-feature prediction function matching the standard workshop reference
float predict_profit_simple(float rd_spend, float admin_spend, float mktg_spend) {
    // Standard workshop weights without State column:
    // W_RD = 0.77884104f, W_ADMIN = 0.0293919f, W_MKTG = 0.03471025f, BIAS = 42989.008f
    return (0.77884104f * rd_spend) +
           (0.0293919f * admin_spend) +
           (0.03471025f * mktg_spend) +
           42989.008165f;
}

// Custom float printer for embedded RISC-V newlib-nano (where %f is disabled)
void print_float(float val) {
    int int_part = (int) val;
    int frac_part = (int)((val - (float)int_part) * 100.0f);
    if (frac_part < 0) frac_part *= -1;
    printf("%d.%02d\n", int_part, frac_part);
}

int main(void) {
    // Sample 1 from 50_Startups.csv (New York startup)
    // Actual profit: 192261.83
    float r0Spend = 165349.2f;
    float a0Spend = 136897.8f;
    float mKSpend = 471784.1f;

    // 1. Prediction using full one-hot encoded model (State = New York)
    float profit_full = predict_profit(r0Spend, a0Spend, mKSpend, STATE_NEW_YORK);
    printf("Predicted profit (6-feature model): $");
    print_float(profit_full);

    // 2. Prediction using standard 3-feature workshop model
    float profit_simple = predict_profit_simple(r0Spend, a0Spend, mKSpend);
    printf("Predicted profit (standard 3-feature): $");
    print_float(profit_simple);

    return 0;
}
