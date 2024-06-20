/*
@Youssef Samy Youssef
*/


#include <stdint.h>

extern uint32_t stack_top;
extern uint32_t _S_TEXT;
extern uint32_t _E_TEXT;
extern uint32_t _S_DATA;
extern uint32_t _E_DATA;
extern uint32_t _S_BSS;
extern uint32_t _E_BSS;

extern void main();
void _default_handler(void);

void _reset();
void NMI_Handler(void) __attribute__((weak, alias("_default_handler")));
void HARD_FAULT_Handler(void) __attribute__((weak, alias("_default_handler")));
void MM_FAULT_Handler(void) __attribute__((weak, alias("_default_handler")));
void BUS_Handler(void) __attribute__((weak, alias("_default_handler")));
void USAGE_FAULT_Handler(void) __attribute__((weak, alias("_default_handler")));


const uint32_t _vectors[] __attribute__((section(".vectors"))) = {
	(uint32_t) &stack_top,
	(uint32_t) &_reset,
	(uint32_t) &NMI_Handler,
	(uint32_t) &HARD_FAULT_Handler,
	(uint32_t) &MM_FAULT_Handler,
	(uint32_t) &BUS_Handler,
	(uint32_t) &USAGE_FAULT_Handler,
};


void _reset(void){
	uint32_t i;

	//copy data from flash to ram
	uint32_t data_size = (uint8_t*)&_E_DATA - (uint8_t*)&_S_DATA;
	uint8_t* P_src = (uint8_t*)&_E_TEXT;
	uint8_t* P_DST = (uint8_t*)&_S_DATA;

	for( i =  0;i<data_size  ; i++){
		 P_DST = (uint8_t*) P_src;
		P_DST++;
		P_src++;
	}


	//init bss
	uint32_t bss_size = (uint8_t*)&_E_BSS - (uint8_t*)&_S_BSS;
	P_DST = (uint8_t*)&_S_BSS;

	for( i =  0;i<bss_size  ; i++){
		 P_DST = (uint8_t)0;
		P_DST++;
	}

	main();
	while(1);
}

void _default_handler(void){
	_reset();
}