#include <stdint.h>
#include "LPC11xx.h"
#include "task_config.h"


task_t task_list[MAX_TASKS];

void TaskAdd(uint32_t delay, uint32_t period, void (*handler)(void))
{
  static uint32_t task_count = 0;

  if (task_count < MAX_TASKS)
  {
    task_list[task_count].delay = delay;

    task_list[task_count].period = period;

    task_list[task_count].handler = handler;

    task_count++;
  }
}

volatile uint32_t tick_count = 0;

void SysTick_Handler(void)
{
  tick_count++;

  for (uint32_t count = 0; count < MAX_TASKS; count++)
  {
    if (task_list[count].handler != 0)
    {
      task_list[count].delay--;

      if (task_list[count].delay == 0)
      {
        task_list[count].handler();
        task_list[count].delay = task_list[count].period;
      }
    }
  }

  // Trigger a PendSV exception to perform a context switch
  SCB->ICSR |= SCB_ICSR_PENDSVSET_Msk;
}

void PendSV_Handler(void)
{
  // Perform a context switch
}

