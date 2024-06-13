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
			OLED_MOSI_SET(); //д����1
    }
		else
		{
			OLED_MOSI_CLR(); //д����0
	  }
    OLED_CLK_CLR();    //��ʱ����������     
    OLED_CLK_SET();    //����1bit����
    Data<<=1; 
	}
}
