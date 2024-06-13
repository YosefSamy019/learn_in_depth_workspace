#include "uart.h"

unsigned char data[30] = "Learn in Depth: Youssef Samy";

void main(){
	UART_send(data);
}