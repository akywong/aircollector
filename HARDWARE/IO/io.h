#ifndef __IO_H_
#define __IO_H_

#include "sys.h"


/***************** IO操作函数宏定义 *********************/
#define IO_ON(x)      x=1  
#define IO_OFF(x)     x=0
#define IO_TOGGLE(x)  x^=1
/****************************** end *********************************/

//气泵控制IO--PC3
#define PUMP_GPIO_RCC_CLK RCC_APB2Periph_GPIOC
#define PUMP_GPIO  GPIOC
#define PUMP_PIN   GPIO_Pin_3
#define PUMP PCout(3)

#define PUMP_ON   IO_ON(PUMP)
#define PUMP_OFF  IO_OFF(PUMP)

//出口阀门控制IO--PC1
#define OUTLET_GPIO_RCC_CLK RCC_APB2Periph_GPIOC
#define OUTLET_GPIO   GPIOC
#define OUTLET_PIN    GPIO_Pin_1
#define OUTLET    PCout(1)

#define OUTLET_OPEN   IO_OFF(OUTLET)
#define OUTLET_CLOSE  IO_ON(OUTLET)




/************************* 函数声明 *********************************/
void IO_Init(void);//初始化

/****************************** end *********************************/






		 				    
#endif
