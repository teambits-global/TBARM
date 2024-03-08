#include "adc.h"

/* ADC Driver macros */

#define ADC_Start()						ADC_CR |= (1<<24)
#define ADC_Stop()						ADC_CR &= ~(1<<24)

#define ADC_AD0_A2D_Wait()				while(!(ADC_DR0 & (1u<<31)))
#define ADC_AD1_A2D_Wait()				while(!(ADC_DR1 & (1u<<31)))

#define MASK_10BIT  0x3FF  // 0000 0011 1111 1111
#define ADC_AD0_A2D_Count()				((ADC_DR0 >> 6) & MASK_10BIT)
#define ADC_AD1_A2D_Count()				((ADC_DR1 >> 6) & MASK_10BIT)

/* ADC Driver Functions */

void ADCInit(void)
{
	ADC_Stop();
}	

unsigned short ADCGetA2D(int input)
{
	unsigned short a2dCount;
	
	ADC_CR = (47<<8) | (1<<input);  // Clock is set to 1MHz and Input is selected

	ADC_Start();
	
	switch(input)
	{
		case 0:	ADC_AD0_A2D_Wait(); a2dCount = ADC_AD0_A2D_Count(); break;
		case 1:	ADC_AD1_A2D_Wait(); a2dCount = ADC_AD1_A2D_Count(); break;
	}

	ADC_Stop();
	
	return 	a2dCount;
}

