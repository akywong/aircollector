#include "io.h"
#include "main.h"
    
//GPIO IO��ʼ��
void IO_Init(void)
{
 GPIO_InitTypeDef  GPIO_InitStructure;
 uint32_t peri;
	
 peri = OUTLET_GPIO_RCC_CLK|PUMP_GPIO_RCC_CLK;
	
 RCC_APB2PeriphClockCmd(peri, ENABLE);	 //ʹ��ʱ��
 //���ÿ��ƹܽų�ʼ���������
 GPIO_InitStructure.GPIO_Pin = PUMP_PIN;				       //���ÿ��ƹܽŶ˿�����
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //�������
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO���ٶ�Ϊ50MHz
 GPIO_Init(PUMP_GPIO, &GPIO_InitStructure);					   //�����趨������ʼ�����ÿ��ƹܽ�
 GPIO_ResetBits(PUMP_GPIO,PUMP_PIN);						         //���ƹܽ������
	
	//���ڷ��ſ��ƹܽų�ʼ���������
	GPIO_InitStructure.GPIO_Pin = OUTLET_PIN;
	GPIO_Init(OUTLET_GPIO, &GPIO_InitStructure);
	
}
 