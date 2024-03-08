#ifndef TASK_CFG_H_
#define TASK_CFG_H_

#define MAX_TASKS 3


typedef struct 
{

  uint32_t delay;

  uint32_t period;

  void (*handler)(void);

} task_t;

void TaskAdd(uint32_t delay, uint32_t period, void (*handler)(void));




#endif /*TSK_CFG_H_*/
