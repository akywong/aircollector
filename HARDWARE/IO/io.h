#ifndef __IO_H_
#define __IO_H_

#include "sys.h"


/***************** IO���������궨�� *********************/
#define IO_ON(x)      x=1  
#define IO_OFF(x)     x=0
#define IO_TOGGLE(x)  x^=1
/****************************** end *********************************/

//���ÿ���IO--PC3
#define PUMP_GPIO_RCC_CLK RCC_APB2Periph_GPIOC
#define PUMP_GPIO  GPIOC
#define PUMP_PIN   GPIO_Pin_3
#define PUMP PCout(3)

#define PUMP_ON   IO_ON(PUMP)
#define PUMP_OFF  IO_OFF(PUMP)

//���ڷ��ſ���IO--PC1
#define OUTLET_GPIO_RCC_CLK RCC_APB2Periph_GPIOC
#define OUTLET_GPIO   GPIOC
#define OUTLET_PIN    GPIO_Pin_1
#define OUTLET    PCout(1)

#define OUTLET_OPEN   IO_OFF(OUTLET)
#define OUTLET_CLOSE  IO_ON(OUTLET)




/************************* �������� *********************************/
void IO_Init(void);//��ʼ��

/****************************** end *********************************/






		 				    
#endif
