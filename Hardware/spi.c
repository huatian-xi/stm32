#include "spi.h"

/*****************************************************************************
 * @name       :void SPI_WriteByte(u8 Data)
 * @date       :2018-08-27 
 * @function   :Write a byte of data using STM32's Software SPI
 * @parameters :Data:Data to be written
 * @retvalue   :None
******************************************************************************/
void SPI_WriteByte(u8 Data)
{
	unsigned char i=0;
	for(i=8;i>0;i--)
	{
	  if(Data&0x80)	
		{
			OLED_MOSI_SET(); //写数据1
    }
		else
		{
			OLED_MOSI_CLR(); //写数据0
	  }
    OLED_CLK_CLR();    //将时钟拉低拉高     
    OLED_CLK_SET();    //发送1bit数据
    Data<<=1; 
	}
}
