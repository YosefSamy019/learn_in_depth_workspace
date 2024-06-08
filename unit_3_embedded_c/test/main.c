#include <stdio.h>

int main(){

	volatile int i=0;
	while(i++ <100) i++;
	
	return 0;
}