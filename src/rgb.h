#ifndef __RGB_H__
#define __RGB_H__

#include "gpio.h"


#define RGB_NONE		0
#define RGB_RED			1
#define RGB_GREEN		2
#define RGB_BLUE		3
#define RGB_YELLOW		4
#define RGB_MAGENTA		5
#define RGB_CYAN		6
#define RGB_WHITE		7
#define RGB_RED_BLINK	8
#define RGB_GREEN_BLINK	9
#define RGB_BLUE_BLINK	10

void RGBSetColor(int clrcode);


#endif

