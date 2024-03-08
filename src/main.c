#include <stdint.h>
#include "LPC11xx.h"

// MCU Chip specific headers

// ECU board specific headers

#include "task_config.h"
#include "task.h"

void Init(void)
{
	// MCU & ECU Inits


	// Configure SysTick to generate interrupts every 10ms
	SysTick_Config(480000);
}

int main(void)
{
	Init();
	
	
	// Add tasks to the task list
	TaskAdd(1, 1, Task1); // @10ms
	TaskAdd(1, 5, Task2); // @20ms
	TaskAdd(1, 10,Task3); // @50ms	

	while(1)
	{

    // Main program loop

	}
}

