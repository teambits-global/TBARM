#ifndef __LCD_H__
#define __LCD_H__

#include "lpc11xx.h"
#include "gpio.h"


// LCD Driver Functions
void LCDInit(void);								
void LCDSetCmd(uint8_t cmd);   
char LCDPutChar(char dat);	
void LCDPutString(char *str);
void LCDPutNum(uint8_t num);

void LCDRowSelect(int option);


#endif
