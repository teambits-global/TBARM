#include "analog.h"



float  DtrmVoltage(void)
{
	uint16_t a2d;
	float volts;
	
	a2d = ADCGetA2D(0);
	
	volts = (float)(a2d*0.00322);
	
	return volts; 
	
}

float  DtrmTemperature(void)
{
	uint16_t a2d;
	float rt;
	
	a2d = ADCGetA2D(1);
	
	rt = (float)a2d/3;  // 1 degree = 10mv
	
	return rt; 
}

