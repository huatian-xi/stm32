//#include "stm32f10x.h"                  // Device header
#include "delay.h"
#include "sys.h"
#include "pwm.h"


/*
	Device：
	STM32 F103;
	无源蜂鸣器signal→PB9;
*/

/*21个对应音阶的频率
	const unsigned int tone_low[7]={3817,3401,3030,2865,2551,2272,2024};
	const unsigned int tone_mid[7]={1912,1703,1517,1432,1275,1136,1012};
	const unsigned int tone_hig[7]={956,851,758,715,637,568,506};
*/
/*	
	[|数组下标 音阶|]
	低|0    1|1    2|2    3|3    4|4    5|5    6|6	  7|
	中|7    1|8    2|9    3|10   4|11   5|12   6|13	  7|
	高|14   1|15   2|16   3|17   4|18   5|19   6|20	  7|
*/

const unsigned int tone[21]={3817,3401,3030,2865,2551,2272,2024,//0-6
														 1912,1703,1517,1432,1275,1136,1012,//7-13
														 956,851,758,715,637,568,506};//14-20

const unsigned char music_tone[89]=
{
	11,8, 7,6,5, 4,11, 8,9,8, 7,7,5, 8,9,8,7, 8,7,6,5, 4,  4,4,			//24
	11,11,12, 8,   7,7,5, 8,   11,11, 12,7,12,11, 7,7,5, 8,   11,8,		//20
	7,6,5, 		4,11, 8,9,8, 7,7,5, 8,9,8,7, 8,7,6,5, 4,   4,4, 				//22
	4,8,7,6,5,4,11,8,9,8,    7,7,5,8,9,8,7,15,14,13,12,11,11  			//23
};//东方红简谱
	
const unsigned char music_time[89]=
{
	4,4, 4,2,2, 4,4, 4,2,2, 4,2,2, 2,2, 2,2, 2,2, 2,2, 8, 8,8,								//24
	4,2,2, 		8,		 4,2,2, 	8, 		4,4, 	2,2,2,2, 	4,2,2, 		8, 		4,4, 	//20
	4,2,2, 		4,4, 	4,2,2, 4,2,2, 	2,2,2,2, 	2,2,2,2, 	8, 8,8,						//22
	4,4,  4,2,2,  4,4,		4,2,2,  4,2,2,  2,2,  2,2,  2,2,  2,2,  8,8  					//23
};//东方红节拍

int main(void)
{
	delay_init();
	unsigned int i;
	unsigned int j;
	pwm_init();

	while (1)
	{
		for(i=0;i<89;i++)
		{
			set_pwm(tone[music_tone[i]],tone[music_tone[i]]/2);
			delay_ms(music_time[i]*50);
			for(j=tone[music_tone[i]]/2;j<tone[music_tone[i]];j++)
			{
				TIM_SetCompare4(TIM4,j);
				delay_us(music_time[i] * 200000L/tone[music_tone[i]]);
			
			}
		}
		TIM_SetCompare4(TIM4,0);
		delay_ms(1000);
		delay_ms(1000);
		delay_ms(1000);
		delay_ms(1000);
		delay_ms(1000);
	}
}
