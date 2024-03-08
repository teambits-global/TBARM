#include "iocon.h"

#define IOCON_Set(pin, fun, mode, hys, adm, i2m, odm) 	 IOCON_##pin = (fun<<0) | (mode<<3) | (hys<<5) | (adm<<7) | (i2m<<8) | (odm <<10) 


void IOConfigAll(void)
{
	/* RGB IO */
	IOCON_Set(PIO1_10, 0, 2, 0, 1, 0, 0);
	IOCON_Set(R_PIO1_2, 1, 2, 0, 1, 0, 0);
	IOCON_Set(PIO2_10, 0, 2, 0, 0, 0, 0);
	
	/**USER KEYS**/
	IOCON_Set(PIO0_3,0,2,1,0,0,0);//UKEY_UP
	IOCON_Set(PIO2_6,0,2,1,0,0,0);//UKEY_DOWN
	IOCON_Set(PIO2_7,0,2,1,0,0,0);//UKEY_LEFT
	IOCON_Set(PIO1_4,0,2,1,1,0,0);//UKEY_RIGHT
	IOCON_Set(PIO2_8,0,2,1,0,0,0);//UKEY_CENTER
	
	/**BUZZER IO**/
	IOCON_Set(PIO0_8,0,1,0,0,0,0);//Buzzer
	
	//** ROTARY ENCODER&SWITCH **//
	IOCON_Set(PIO1_5,0,2,1,0,0,0);// Rotary_A
	IOCON_Set(PIO1_8,0,2,1,0,0,0);// Rotary_B
	IOCON_Set(PIO0_7,0,2,1,0,0,0);// Rotary_S
	
	//** ANALOG IO **//
	IOCON_Set(R_PIO0_11,2,0,1,0,0,0);// vPOT
	IOCON_Set(R_PIO1_0,2,0,1,0,0,0);//LM35
	
	//** I2C IO **//
	IOCON_Set(PIO0_4,1,0,0,0,0,0); // SCL 
	IOCON_Set(PIO0_5,1,0,0,0,0,0); // SDA 
	
	//** SPI IO **//
	IOCON_Set(PIO2_11,1,2,0,0,0,0); // SCK 
	IOCON_Set(PIO0_9,1,2,0,0,0,0);  // MOSI
	IOCON_Set(PIO0_2,0,2,0,0,0,0);  //DAC_Select
	
	//** UART-USB IO **//
	IOCON_Set(PIO1_6,1,2,0,0,0,0);// RXD 
	IOCON_Set(PIO1_7,1,2,0,0,0,0);// TXD 
	
	//** PWM LED IO **//
	IOCON_Set(R_PIO1_1,3,1,0,1,0,0);// PWM 
}



