#include "lcd.h"


/* LCD IO Map 
LCD 4-bit Bus : PIO3_0 to PIO3_3
LCD RS: PIO0_6
LCD EN:	PIO1_11
LCD RW: GND
*/

#define LCD_Write_4Bit(dat)	GPIO3_DATA = (GPIO3_DATA & ~(0xf)) | (dat)

#define LCD_RS_Command()	GPIO0SetPin(6, LOW)
#define LCD_RS_Data()		GPIO0SetPin(6, HIGH)

#define LCD_EN_HIGH()		GPIO1SetPin(11, HIGH)
#define LCD_EN_LOW()		GPIO1SetPin(11, LOW)


void LCDDelay(uint32_t ms)
{
	uint32_t ctr1,ctr2;
  
	for(ctr1=0;ctr1<ms;ctr1++)
	{
		for(ctr2=0;ctr2<(112*48);ctr2++);
	} 
}	

void LCDSetCmd(uint8_t cmd)   
{
	uint8_t cmd_h, cmd_l;
	
	cmd_l = (cmd >>0) & 0xF;
	cmd_h = (cmd >>4) & 0xF;
		
	LCD_RS_Command();

	LCD_EN_HIGH();
	LCD_Write_4Bit(cmd_h);
	LCD_EN_LOW();

	LCD_EN_HIGH();
	LCD_Write_4Bit(cmd_l);
	LCD_EN_LOW();
	LCDDelay(1);  
}

void LCDRowSelect(int option)
{
	switch(option)
	{
		case 0: LCDSetCmd(0x80); break;
		case 1: LCDSetCmd(0xC0); break;
	}
}	

char LCDPutChar(char dat)
{
  unsigned char dat_h, dat_l;
	
	dat_l = (dat >>0) & 0xF;
	dat_h = (dat >>4) & 0xF;
		
	LCD_RS_Data();

	LCD_EN_HIGH();
	LCD_Write_4Bit(dat_h);
	LCD_EN_LOW();

	LCD_EN_HIGH();
	LCD_Write_4Bit(dat_l);
	LCD_EN_LOW();
	LCDDelay(1);  
	
	return dat;
}	

void LCDPutNum(uint8_t num)
{
	uint8_t ones, tens;
	
	tens = num/10;
	ones = num%10;
	
	LCDPutChar(tens+48);
	LCDPutChar(ones+48);
}

void LCDPutString(char *str)
{
	while(*str)
	{
		LCDPutChar(*str);
		str++;
	}	
}


void LCDInit(void)
{
	// 4 bit initialisation
	LCDDelay(50);  // wait for >40ms
	LCDSetCmd(0x02);	/* 4bit mode */
	LCDSetCmd(0x28);	/* Initialization of 16X2 LCD in 4bit mode */
	LCDSetCmd(0x0C);	/* Display ON Cursor OFF */
	LCDSetCmd(0x06);	/* Auto Increment cursor */
	LCDSetCmd(0x01);	/* Clear display */
	LCDSetCmd(0x80);	/* Cursor at home position */
}	
