#ifndef _SPI_H_
#define _SPI_H_
#include "sys.h"

//本测试程序使用的是软件模拟SPI接口驱动
//SPI的数据引脚定义和时钟引脚定义都可以任意修改
//修改引脚定义后，需要对应修改oled.c中OLED_Init_GPIO函数里面引脚初始化

//--------------SPI总线引脚定义-----------------------
#define OLED_MOSI      GPIO_Pin_15  //OLED屏SPI写数据信号
#define OLED_CLK       GPIO_Pin_13  //OLED屏SPI时钟信号

//--------------SPI端口操作定义---------------------
#define	OLED_MOSI_SET()  	GPIO_SetBits(GPIOB,OLED_MOSI) 
#define	OLED_MOSI_CLR()  	GPIO_ResetBits(GPIOB,OLED_MOSI) 
  
#define	OLED_CLK_SET()  	GPIO_SetBits(GPIOB,OLED_CLK)    
#define	OLED_CLK_CLR()  	GPIO_ResetBits(GPIOB,OLED_CLK)    

//SPI写数据函数
void SPI_WriteByte(u8 Data);
#endif
