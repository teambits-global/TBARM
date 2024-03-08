#include "rotary.h"


volatile static int rotary_dir, rotary_count; 

void PIOINT1_IRQHandler(void)  // CPU jumps here whenever there is a Falling Edge on PIO1_5
{
	int state;
	
	state = GPIO1GetPinState(8);  // Check the ENC_B current state
	
	if(HIGH == state)
	{ 
		rotary_dir = 0;   // Clockwise Movement	
		rotary_count++;
	}
	else
	{
		rotary_dir = 1;   // Counter Clockwise Movement	
		rotary_count--;
	}		

  // Before returning from ISR, Clear the interrupt and give 2 NOPs delay
  EINT_Clr(1,5);

  __NOP();
  __NOP();
}	



int RotaryGetDirection(void)
{
	return rotary_dir;
}	

int RotaryGetCount(void)
{
	return rotary_count;
}	

void RotaryResetCount(void)
{
	rotary_count =0;
}	

int RotaryKeyGetState(void)
{
	int keystate = RELEASE;
	
	if(LOW == GPIO0GetPinState(7))
	{
		keystate = TOUCH;
	}	

	return keystate;	
}	

void RotaryKeyGetClicks(int *count)
{
	int rkeycurr;
	static int rkeyprev = RELEASE;
	
	rkeycurr = RotaryKeyGetState();
	if(RELEASE == rkeycurr)
	{
		if(TOUCH == rkeyprev)
		{
			*count+=1;
		}
	}
	rkeyprev = rkeycurr;
	
}	


void RotaryInit(void)
{
	EINT1Init();
	RotaryResetCount();
}	

