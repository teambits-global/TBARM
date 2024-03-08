#ifndef __GPIO_H__
#define __GPIO_H__

#include "lpc11xx.h"


#define INPUT  0
#define OUTPUT 1

#define LOW    0
#define HIGH   1
#define TOGGLE 2

/* GPIO Driver Function Prototype Declarations */

void GPIO0SetDirection(int pin, int dir); // pin: 0 to 11,  dir: INPUT/ OUTPUT
void GPIO1SetDirection(int pin, int dir);
void GPIO2SetDirection(int pin, int dir);
void GPIO3SetDirection(int pin, int dir);

void GPIO0SetPin(int pin, int option); // pin: 0 to 11, option: LOW/ HIGH/ TOGGLE
void GPIO1SetPin(int pin, int option);
void GPIO2SetPin(int pin, int option);
void GPIO3SetPin(int pin, int option);

int GPIO0GetPinState(int pin); // return value: LOW/HIGH
int GPIO1GetPinState(int pin);
int GPIO2GetPinState(int pin);                                     
int GPIO3GetPinState(int pin);

void GPIOConfigAll(void);

#endif
