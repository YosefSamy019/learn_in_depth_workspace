#include<stdint.h>

#define RCC_BASE_ADDRESS 	0x40021000
#define GPIOA_BASE_ADDRESS 	0x40010800

#define APB2ENR_REG 	(*((volatile uint32_t*)(RCC_BASE_ADDRESS + 0x18)))
#define CRH_REG 		(*((volatile uint32_t*)(GPIOA_BASE_ADDRESS + 0x04)))
#define GPIOA_ODR_REG 	(*((volatile uint32_t*)(GPIOA_BASE_ADDRESS + 0x0c)))

#define DELAY() do{volatile uint32_t x=0; while(x++<100000);} while(0)

#define SET_BIT(reg,no) reg |= (1<<no)
#define CLR_BIT(reg,no) reg &= (~(1<<no))

char arr1[100] = "Hello, Embedded C"; 	//data
char arr2[50];	
						//bss
const char arr3[25]="I am bored";		//rodata


void main(){
	//enable RCC IOPAEN
	SET_BIT(APB2ENR_REG,2);

	//make pin o/p (2 = 0010)
	CLR_BIT(CRH_REG,20);
	SET_BIT(CRH_REG,21);
	CLR_BIT(CRH_REG,22);
	CLR_BIT(CRH_REG,23);


	while(1){
		SET_BIT(GPIOA_ODR_REG,13);
		DELAY();
		CLR_BIT(GPIOA_ODR_REG,13);
		
		DELAY();
	}
}
