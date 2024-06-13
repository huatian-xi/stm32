#include "pwm.h"

void pwm_init(void)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	TIM_OCInitTypeDef TIM_OCInitStructure;
	GPIO_InitTypeDef GPIO_InitStructure;
	
	//ʹ��TIM4  TIM4_CH4
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4,ENABLE);
	/*GPIO PB9 �˿�ʱ�� ͬʱҪ��AFIOʱ�� �˿ڽ�����������TIM4*/
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB|RCC_APB2Periph_AFIO , ENABLE);

	//PB9���ø����������ģʽ
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	/*��ʱ������ ����Ƶ��*/
	TIM_TimeBaseStructure.TIM_Period = 3819 - 1;//����ֵ ��Χ0 - 3816
	TIM_TimeBaseStructure.TIM_Prescaler = 72 -1;//72MHZ/72 = 1M 1s 1000000
	TIM_TimeBaseStructure.TIM_ClockDivision = 0;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;//���ϼ���ģ
	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure);
	
	/*PWM1ģʽ����: TIM4_CH4 */
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;//PWMģʽ1
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse = 3816/2;/*���ñȽ�ֵ���Ƚ�ֵ����ռ�ձȣ���Χ�ɼ���ֵ�ķ�Χȷ��*/
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	
	TIM_OC4Init(TIM4, &TIM_OCInitStructure);
	//ʹ��Ԥװ�ؼĴ���
	TIM_OC4PreloadConfig(TIM4, TIM_OCPreload_Enable);
	//ʹ���Զ���װ�ؼĴ���
	TIM_ARRPreloadConfig(TIM4, ENABLE);
	
	//ʹ��TIM4����
	TIM_Cmd(TIM4, ENABLE);
	
}
void set_pwm(unsigned int  period,unsigned int pulse)
{
	TIM_SetAutoreload(TIM4, period);
	TIM_SetCompare4(TIM4,pulse);
}
