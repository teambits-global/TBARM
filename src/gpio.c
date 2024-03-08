#include "gpio.h"


// IO Direction Configuration Macroes
#define GPIO0_Pin_Config_Input(pin)		GPIO0_DIR &= ~(1<<pin)
#define GPIO0_Pin_Config_Output(pin)	GPIO0_DIR |=  (1<<pin)

#define GPIO1_Pin_Config_Input(pin)		GPIO1_DIR &= ~(1<<pin)
#define GPIO1_Pin_Config_Output(pin)	GPIO1_DIR |=  (1<<pin)

#define GPIO2_Pin_Config_Input(pin)		GPIO2_DIR &= ~(1<<pin)
#define GPIO2_Pin_Config_Output(pin)	GPIO2_DIR |=  (1<<pin)

#define GPIO3_Pin_Config_Input(pin)		GPIO3_DIR &= ~(1<<pin)
#define GPIO3_Pin_Config_Output(pin)	GPIO3_DIR |=  (1<<pin)

// Port Pin Write Macroes
#define GPIO0_Pin_Set_High(pin)			GPIO0_DATA |= (1<<pin)
#define GPIO1_Pin_Set_High(pin)			GPIO1_DATA |= (1<<pin)
#define GPIO2_Pin_Set_High(pin)			GPIO2_DATA |= (1<<pin)
#define GPIO3_Pin_Set_High(pin)			GPIO3_DATA |= (1<<pin)

#define GPIO0_Pin_Set_Low(pin)			GPIO0_DATA &= ~(1<<pin)
#define GPIO1_Pin_Set_Low(pin)			GPIO1_DATA &= ~(1<<pin)
#define GPIO2_Pin_Set_Low(pin)			GPIO2_DATA &= ~(1<<pin)
#define GPIO3_Pin_Set_Low(pin)			GPIO3_DATA &= ~(1<<pin)

#define GPIO0_Pin_Toggle(pin)			GPIO0_DATA ^= (1<<pin)
#define GPIO1_Pin_Toggle(pin)			GPIO1_DATA ^= (1<<pin)
#define GPIO2_Pin_Toggle(pin)			GPIO2_DATA ^= (1<<pin)
#define GPIO3_Pin_Toggle(pin)			GPIO3_DATA ^= (1<<pin)

// Port Pin Read Drivers
#define GPIO0_Pin_Get_State(pin)		(GPIO0_DATA & (1<<pin))?1:0
#define GPIO1_Pin_Get_State(pin)		(GPIO1_DATA & (1<<pin))?1:0
#define GPIO2_Pin_Get_State(pin)		(GPIO2_DATA & (1<<pin))?1:0
#define GPIO3_Pin_Get_State(pin)		(GPIO3_DATA & (1<<pin))?1:0

void GPIO0SetDirection(int pin, int dir)
{
	switch(dir)
	{
		case INPUT:		GPIO0_Pin_Config_Input(pin);  break;
		case OUTPUT:	GPIO0_Pin_Config_Output(pin); break;
	}
}

void GPIO1SetDirection(int pin, int dir)
{
	switch(dir)
	{
		case INPUT:		GPIO1_Pin_Config_Input(pin);  break;
		case OUTPUT:	GPIO1_Pin_Config_Output(pin); break;
	}
}

void GPIO2SetDirection(int pin, int dir)
{
	switch(dir)
	{
		case INPUT:		GPIO2_Pin_Config_Input(pin);  break;
		case OUTPUT:	GPIO2_Pin_Config_Output(pin); break;
	}
}

void GPIO3SetDirection(int pin, int dir)
{
	switch(dir)
	{
		case INPUT:		GPIO3_Pin_Config_Input(pin);  break;
		case OUTPUT:	GPIO3_Pin_Config_Output(pin); break;
	}
}

void GPIO0SetPin(int pin, int option)
{
	switch(option)
	{
		case LOW:		GPIO0_Pin_Set_Low(pin);  break;
		case HIGH:		GPIO0_Pin_Set_High(pin); break;
		case TOGGLE:	GPIO0_Pin_Toggle(pin); 	 break;
	}
}

void GPIO1SetPin(int pin, int option)
{
	switch(option)
	{
		case LOW:		GPIO1_Pin_Set_Low(pin);  break;
		case HIGH:		GPIO1_Pin_Set_High(pin); break;
		case TOGGLE:	GPIO1_Pin_Toggle(pin); 	 break;
	}
}

void GPIO2SetPin(int pin, int option)
{
	switch(option)
	{
		case LOW:		GPIO2_Pin_Set_Low(pin);  break;
		case HIGH:		GPIO2_Pin_Set_High(pin); break;
		case TOGGLE:	GPIO2_Pin_Toggle(pin); 	 break;
	}
}

void GPIO3SetPin(int pin, int option)
{
	switch(option)
	{
		case LOW:		GPIO3_Pin_Set_Low(pin);  break;
		case HIGH:		GPIO3_Pin_Set_High(pin); break;
		case TOGGLE:	GPIO3_Pin_Toggle(pin); 	 break;
	}
}

int GPIO0GetPinState(int pin)
{
	int state;
	
	state = GPIO0_Pin_Get_State(pin);
	
	return state;
}

int GPIO1GetPinState(int pin)
{
	int state;
	
	state = GPIO1_Pin_Get_State(pin);
	
	return state;
}

int GPIO2GetPinState(int pin)
{
	int state;
	
	state = GPIO2_Pin_Get_State(pin);
	
	return state;
}

int GPIO3GetPinState(int pin)
{
	int state;
	
	state = GPIO3_Pin_Get_State(pin);
	
	return state;
}

void GPIOConfigAll(void)
{
	// User Keys specific GPIO Pins (Input)
	GPIO2SetDirection(6,INPUT);
	GPIO2SetDirection(7,INPUT);
	GPIO0SetDirection(3,INPUT);
	GPIO2SetDirection(8,INPUT);
	GPIO1SetDirection(4,INPUT);

	// Rotary Encoder specific GPIO Pins (Input)
	GPIO1SetDirection(5,INPUT);
	GPIO1SetDirection(8,INPUT);
	GPIO0SetDirection(7,INPUT);

	// RGB specific GPIO Pins (Output)	
	GPIO2SetDirection(10,OUTPUT);
	GPIO1SetDirection(10,OUTPUT);
	GPIO1SetDirection(2,OUTPUT);

	// Buzzer specific GPIO Pin (Output)
	GPIO0SetDirection(8,OUTPUT);

	// DAC Select GPIO Pin (Output)
	GPIO0SetDirection(2,OUTPUT);
	
	// LCD specific GPIO Pins (Output)
	GPIO0SetDirection(6,OUTPUT);
	GPIO1SetDirection(11,OUTPUT);
	GPIO3SetDirection(0,OUTPUT);
	GPIO3SetDirection(1,OUTPUT);
	GPIO3SetDirection(2,OUTPUT);
	GPIO3SetDirection(3,OUTPUT);
}


