#include "driver.h"
#include <stdint.h>
#include <stdio.h>

//void Delay(int nCount)
//{
//	for(; nCount != 0; nCount--);
//}

volatile unsigned long p=0,count = 0;


int getPressureVal(){
  count++;
  p = (unsigned char )(GPIOA_IDR & 0xFF);
  return (unsigned long)(GPIOA_IDR & 0xFF);
}

void Set_Alarm_actuator(int i){
	if (i == 1){
		SET_BIT(GPIOA_ODR,13);
	}
	else if (i == 0){
		RESET_BIT(GPIOA_ODR,13);
	}
}

void GPIO_INITIALIZATION (){
	SET_BIT(APB2ENR, 2);
 	
volatile int i=0;
 for (i=0;i<10000;i++);
 
	GPIOA_CRL &= 0xFF0FFFFF;
	GPIOA_CRL |= 0x00000000;
 
	GPIOA_CRH &= 0xFF0FFFFF;
	GPIOA_CRH |= 0x22222222;
}
