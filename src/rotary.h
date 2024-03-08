#ifndef __ROTARY_H__
#define __ROTARY_H__

#include "gpio.h"
#include "eint.h"
#include "ukeys.h"

// Function Prototypes
void RotaryInit(void);
int  RotaryGetDirection(void);
int  RotaryGetCount(void);
void RotaryResetCount(void);
int  RotaryKeyGetState(void);
void RotaryKeyGetClicks(int *count);

#endif

