
/*! @file hsc.c
    @brief Sensor driver for hsc sensor */
#include "spi.h"
#include "hsc_spi.h"
#include "hsc.h"

int hsc_get_data(float*pressure,float*temperature)
{
	u8 buf[4];
	u8 readn=0;
	int status;
	int temperature_count;
	int pressure_count;
	readn = hsc_read_reg(buf,4);
	if(readn!=4){
		return -1;
	}
	status = (buf[0]&0xc0)>>6;
	if(0!=status){
		return (0-status);
	}
	pressure_count = (((int)(buf[0]&0x3F))<<8)|buf[1];
	temperature_count = ((((int)buf[3])<<8)|buf[3])>>5;
	*pressure = (((float)(pressure_count-OUTPUT_MIN))*(PRESSURE_MAX-PRESSURE_MIN))/((float)(OUTPUT_MAX-OUTPUT_MIN))+PRESSURE_MIN;
	*temperature = ((float)temperature_count) * 200.0 / 2047 - 50.0;
	
	return 0;
}
