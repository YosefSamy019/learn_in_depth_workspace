
#define UARTDR_BASE_ADDRESS (*((volatile unsigned int *)0x101f1000))

#include "uart.h"

void UART_send (unsigned char *str){
	while(*str != '\0'){
		UARTDR_BASE_ADDRESS = *str;
		str++;
	}
}