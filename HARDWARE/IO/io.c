#include "io.h"
#include "main.h"
    
//GPIO IO初始化
void IO_Init(void)
{
 GPIO_InitTypeDef  GPIO_InitStructure;
 uint32_t peri;
	
 peri = OUTLET_GPIO_RCC_CLK|PUMP_GPIO_RCC_CLK;
	
 RCC_APB2PeriphClockCmd(peri, ENABLE);	 //使能时钟
 //气泵控制管脚初始化（输出）
 GPIO_InitStructure.GPIO_Pin = PUMP_PIN;				       //气泵控制管脚端口配置
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
 GPIO_Init(PUMP_GPIO, &GPIO_InitStructure);					   //根据设定参数初始化气泵控制管脚
 GPIO_ResetBits(PUMP_GPIO,PUMP_PIN);						         //控制管脚输出低
	
	//出口阀门控制管脚初始化（输出）
	GPIO_InitStructure.GPIO_Pin = OUTLET_PIN;
	GPIO_Init(OUTLET_GPIO, &GPIO_InitStructure);
	
}
 