
#ifndef __ADC_H__
#define __ADC_H__

#include <stdint.h>
#include "lpc11xx.h"

/* ADC Driver Function Prototype Declarations */
void ADCInit(void);
uint16_t ADCGetA2D(int input);

#endif
