#include "pwm.h"

void pwm_init(void)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	TIM_OCInitTypeDef TIM_OCInitStructure;
	GPIO_InitTypeDef GPIO_InitStructure;
	
	//使能TIM4  TIM4_CH4
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4,ENABLE);
	/*GPIO PB9 端口时钟 同时要能AFIO时钟 端口交给其他外设TIM4*/
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB|RCC_APB2Periph_AFIO , ENABLE);

	//PB9配置复用推挽输出模式
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	/*定时器配置 产生频率*/
	TIM_TimeBaseStructure.TIM_Period = 3819 - 1;//计数值 范围0 - 3816
	TIM_TimeBaseStructure.TIM_Prescaler = 72 -1;//72MHZ/72 = 1M 1s 1000000
	TIM_TimeBaseStructure.TIM_ClockDivision = 0;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;//向上计数模
	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure);
	
	/*PWM1模式已置: TIM4_CH4 */
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;//PWM模式1
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse = 3816/2;/*设置比较值，比较值决定占空比，范围由计数值的范围确定*/
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	
	TIM_OC4Init(TIM4, &TIM_OCInitStructure);
	//使能预装载寄存器
	TIM_OC4PreloadConfig(TIM4, TIM_OCPreload_Enable);
	//使能自动重装载寄存器
	TIM_ARRPreloadConfig(TIM4, ENABLE);
	
	//使能TIM4计数
	TIM_Cmd(TIM4, ENABLE);
	
}
void set_pwm(unsigned int  period,unsigned int pulse)
{
	TIM_SetAutoreload(TIM4, period);
	TIM_SetCompare4(TIM4,pulse);
}
