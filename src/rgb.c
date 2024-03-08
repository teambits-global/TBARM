#include "rgb.h"

#define TURN_OFF	1
#define TURN_ON	  	2  
#define BLINK	    3

static void RedLEDSet(int option)
{
	switch(option)
	{
		case TURN_OFF:	GPIO2SetPin(10,HIGH); 	break;
		case TURN_ON:   GPIO2SetPin(10,LOW); 	break;
		case BLINK:     GPIO2SetPin(10,TOGGLE); break;
	}	
}	

static void GreenLEDSet(int option)
{
	switch(option)
	{
		case TURN_OFF:	GPIO1SetPin(2,HIGH); 	break;
		case TURN_ON:   GPIO1SetPin(2,LOW); 	break;
		case BLINK:     GPIO1SetPin(2,TOGGLE); 	break;
	}	
}	

static void BlueLEDSet(int option)
{
	switch(option)
	{
		case TURN_OFF:	GPIO1SetPin(10,HIGH); 	break;
		case TURN_ON:   GPIO1SetPin(10,LOW); 	break;
		case BLINK:     GPIO1SetPin(10,TOGGLE); break;
	}	
}	


void RGBSetColor(int clrcode)
{
	switch(clrcode)
	{
		case RGB_NONE:				RedLEDSet(TURN_OFF); 	GreenLEDSet(TURN_OFF); 	BlueLEDSet(TURN_OFF); 	break;
		case RGB_RED:				RedLEDSet(TURN_ON);  	GreenLEDSet(TURN_OFF); 	BlueLEDSet(TURN_OFF);	break;
		case RGB_GREEN:				RedLEDSet(TURN_OFF); 	GreenLEDSet(TURN_ON);  	BlueLEDSet(TURN_OFF);	break;
		case RGB_BLUE:				RedLEDSet(TURN_OFF); 	GreenLEDSet(TURN_OFF); 	BlueLEDSet(TURN_ON); 	break;
		case RGB_YELLOW:			RedLEDSet(TURN_ON);  	GreenLEDSet(TURN_ON); 	BlueLEDSet(TURN_OFF); 	break;
		case RGB_MAGENTA:			RedLEDSet(TURN_ON);  	GreenLEDSet(TURN_OFF);	BlueLEDSet(TURN_ON); 	break;
		case RGB_CYAN:				RedLEDSet(TURN_OFF); 	GreenLEDSet(TURN_ON);	BlueLEDSet(TURN_ON); 	break;
		case RGB_WHITE:				RedLEDSet(TURN_ON);  	GreenLEDSet(TURN_ON);	BlueLEDSet(TURN_ON); 	break;
		case RGB_RED_BLINK:			RedLEDSet(BLINK);  		GreenLEDSet(TURN_OFF);	BlueLEDSet(TURN_OFF); 	break;
		case RGB_GREEN_BLINK:		RedLEDSet(TURN_OFF); 	GreenLEDSet(BLINK);		BlueLEDSet(TURN_OFF); 	break;
		case RGB_BLUE_BLINK:		RedLEDSet(TURN_OFF);  	GreenLEDSet(TURN_OFF);	BlueLEDSet(BLINK); 		break;
	}	
}	


