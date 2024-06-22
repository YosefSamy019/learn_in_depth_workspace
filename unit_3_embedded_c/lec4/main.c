/*
@Youssef Samy Youssef
*/

#define SYSCTL_RCGC2_R 		(*((volatile unsigned long*)(0x400FE000+0X108)))
#define GPIO_PORTF_DATA_R 	(*((volatile unsigned long*)(0x40025000+0X3fc)))
#define GPIO_PORTF_DIR_R 	(*((volatile unsigned long*)(0x40025000+0X400)))
#define GPIO_PORTF_DEN_R 	(*((volatile unsigned long*)(0x40025000+0X51C)))

void main()
{
	volatile unsigned i;

	SYSCTL_RCGC2_R = 0X20;

	for(i=0;i<2000;i++);

	GPIO_PORTF_DEN_R |= 1<<3;
	GPIO_PORTF_DIR_R |= 1<<3;

	while(1){
		GPIO_PORTF_DATA_R ^= 1<<3;

		for(i=0;i<2000;i++);
	}

	return 0;
}

