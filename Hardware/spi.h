#ifndef _SPI_H_
#define _SPI_H_
#include "sys.h"

//�����Գ���ʹ�õ������ģ��SPI�ӿ�����
//SPI���������Ŷ����ʱ�����Ŷ��嶼���������޸�
//�޸����Ŷ������Ҫ��Ӧ�޸�oled.c��OLED_Init_GPIO�����������ų�ʼ��

//--------------SPI�������Ŷ���-----------------------
#define OLED_MOSI      GPIO_Pin_15  //OLED��SPIд�����ź�
#define OLED_CLK       GPIO_Pin_13  //OLED��SPIʱ���ź�

//--------------SPI�˿ڲ�������---------------------
#define	OLED_MOSI_SET()  	GPIO_SetBits(GPIOB,OLED_MOSI) 
#define	OLED_MOSI_CLR()  	GPIO_ResetBits(GPIOB,OLED_MOSI) 
  
#define	OLED_CLK_SET()  	GPIO_SetBits(GPIOB,OLED_CLK)    
#define	OLED_CLK_CLR()  	GPIO_ResetBits(GPIOB,OLED_CLK)    

//SPIд���ݺ���
void SPI_WriteByte(u8 Data);
#endif
