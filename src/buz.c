#include "buz.h"


void BuzSet(int option)
{
	switch(option)
	{
		case BUZ_OFF:	GPIO0SetPin(8,LOW);  	break;
		case BUZ_ON:	GPIO0SetPin(8,HIGH); 	break;
		case BUZ_BEEP:	GPIO0SetPin(8,TOGGLE); 	break;
	}	
}	
