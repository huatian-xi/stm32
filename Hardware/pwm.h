#ifndef _PWM_H_
#define _PWM_H_

#include "sys.h"
#include <stm32f10x.h>

void pwm_init(void);
void set_pwm(unsigned int  period,unsigned int pulse);

#endif
