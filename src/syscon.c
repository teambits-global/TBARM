#include "syscon.h"

/* Power Down Disable Macro */
#define PowerDown_Disable(bp)		SYSCON_PDRUNCFG &= ~(1<<bp)

/* PRESET Deassert Macro */
#define Preset_Deassert(bp)			SYSCON_PRESETCTRL |= (1<<bp)

/* Clock Divider for PCLK_SPI Macro */
#define SPI_PCLK_Div(val)			SYSCON_SPICLKDIV = val 

/* Clock Divider for PCLK_UART Macro */
#define UART_PCLK_Div(val)			SYSCON_UARTCLKDIV = val 

#define PCLK_Enable(bp)				SYSCON_SYSAHBCLKCTRL |=  (1<<bp)

void SystemConfigAll(void)
{
	/* PCLK Enable for all the individual Peripherals */
	PCLK_Enable(5);  // PCLK_I2C  Enabled
	PCLK_Enable(6);  // PCLK_GPIO Enabled
	PCLK_Enable(9);  // PCLK_GPT0 Enabled
	PCLK_Enable(10); // PCLK_GPT1 Enabled
	PCLK_Enable(11); // PCLK_SPI0 Enabled
	PCLK_Enable(12); // PCLK_UART Enabled
	PCLK_Enable(13); // PCLK_ADC  Enabled
	PCLK_Enable(15); // PCLK_WDT  Enabled
	PCLK_Enable(16); // PCLK_IOCON Enabled
	PCLK_Enable(17); // PCLK_CAN Enabled
	
	/* Set Clock Divider for PCLK_SPI and PCLK_UART */
	SPI_PCLK_Div(1);  // PCLK_SPI  = 48MHz  
	UART_PCLK_Div(1); // PCLK_UART = 48MHz 
	
	/* Preset Deassert for SPI, I2C and CAN */
	Preset_Deassert(0); // Preset Deasserted for SPI
	Preset_Deassert(1); // Preset Deasserted for I2C
	//Preset_Deassert(3); // Preset Deasserted for CAN
	
	/* Power Down Disable for ADC and Watchdog */
	PowerDown_Disable(4); // Power Down disable for ADC
	PowerDown_Disable(6); // Power Down disable for WDT
}

