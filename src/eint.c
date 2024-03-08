#include "eint.h"

/* EINT Macores */
#define EINT_Trigger_Edge(port,pin)			GPIO##port##_IS  &= ~(1<<pin)
#define EINT_Trigger_Both_Edge(port,pin)	GPIO##port##_IBE |= (1<<pin)
#define EINT_Trigger_Single_Edge(port,pin)	GPIO##port##_IBE &= ~(1<<pin)
#define EINT_Trigger_Fall_Edge(port,pin)	GPIO##port##_IEV |=  (1<<pin)
#define EINT_Trigger_Rise_Edge(port,pin)	GPIO##port##_IEV &= ~(1<<pin)

#define EINT_Trigger_Level(port,pin)		GPIO##port##_IS  |=  (1<<pin)
#define EINT_Trigger_High_Level(port,pin)	GPIO##port##_IEV |=  (1<<pin)
#define EINT_Trigger_Low_Level(port,pin)	GPIO##port##_IEV &= ~(1<<pin)

#define EINT_Enable(port, pin)				GPIO##port##_IE |=  (1<<pin)


void EINT1Init(void)
{
	// Enable the Edge Trigger
	EINT_Trigger_Edge(1,5);
	
	// Enable Single Edge Trigger
	EINT_Trigger_Single_Edge(1,5);
	
	// Enable Falling Edge Trigger
	EINT_Trigger_Fall_Edge(1,5);
	
	// Enable EINT1 IRQ
	NVIC_EnableIRQ(EINT1_IRQn);
	
	// Enable EITN1 in GPIO block
	EINT_Enable(1,5);
}	

