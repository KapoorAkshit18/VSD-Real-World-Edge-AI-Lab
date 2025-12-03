include <stdio.h>
#include <metal/cpu.h>
#include <metal/led.h>
#include <metal/button.h>
#include <metal/switch.h>

#define RTC_FREQ     32768

#define x1 8.66383692e+01
#define x2 -8.72645791e+02
#define x3 7.86007422e+02
#define x4 7.73467193e-01
#define x5 3.28845975e-02
#define x6 3.66100259e-02

#define b 42467.52924853278   // bias

// predict function
float predict (float inp1, float inp2, float inp3){
	return x1*inp1 + x*inp2 + x3* inp3 + b;
}

void print_float(float val)   // directly cannot print so, this function
{
	int int_part = (int) val;
	int frac_part = (int)((val - int_part)*100);  // 2 decimal places
	if (frac_part < 0) frac_part *= -1;
		printf("%d.%02d", int_part, frac_part);


}


int main (void)
{
float r0Spend=165349.2f;  // from csv of startup
        float a0Spend= 136897.8f;
        float mKSpend=471784.1f;
        float profit;
        profit=predict(r0Spend,aDSpend,mKSpend);
        printf("profit is :- %f", profit);
        //return
        return 0;
}

