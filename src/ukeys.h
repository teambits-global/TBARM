#ifndef __UKEYS_H__
#define __UKEYS_H__

#include "gpio.h"


#define TOUCH    1
#define RELEASE  2

int UserKeyCGetState(void);
int UserKeyLGetState(void);
int UserKeyRGetState(void);
int UserKeyUGetState(void);
int UserKeyDGetState(void);

void UserKeyCGetClicks(int *count);
void UserKeyLGetClicks(int *count);
void UserKeyRGetClicks(int *count);
void UserKeyUGetClicks(int *count);
void UserKeyDGetClicks(int *count);

#endif




