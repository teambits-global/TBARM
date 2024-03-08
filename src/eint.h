#ifndef __EINT_H__
#define __EINT_H__

#include "lpc11xx.h"

#define EINT_Clr(port, pin)		GPIO##port##_IC  =  (1<<pin) 

void EINT1Init(void);

#endif

