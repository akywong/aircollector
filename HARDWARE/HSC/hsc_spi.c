#include "hsc_spi.h"
#include "delay.h"
#include "usart.h"
#include "spi.h"

/////Ó²¼þSPI
#define hsc_spi_init()         SPI1_SetMode(SPI_CPOL_Low,SPI_CPHA_1Edge)
#define hsc_cs_h()             HSC_CS_H()
#define hsc_cs_l()             HSC_CS_L()

u8 hsc_read_reg(u8 *data, u8 count)
{
	u8 i;
	
	hsc_spi_init();
	hsc_cs_l();
	i=SPI1_ReadByte(data,count);
	hsc_cs_h();
	
	return i;
}


void hsc_delay_ms(uint32_t period)
{
	int i,j;
  for(i=0;i<period;i++){
		for(j=0;j<100000;j++) {
			__nop();
		}
	}
}
