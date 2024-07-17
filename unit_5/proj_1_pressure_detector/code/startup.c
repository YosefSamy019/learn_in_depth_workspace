/*
	@Youssef Samy Youssef
	Startup.c file for Cortex-m3
*/


extern unsigned int _TEXT_START;
extern unsigned int _TEXT_END;
extern unsigned int _RODATA_START;
extern unsigned int _RODATA_END;
extern unsigned int _DATA_START;
extern unsigned int _DATA_END;
extern unsigned int _BSS_START;
extern unsigned int _BSS_END;
extern unsigned int _STACK_TOP;

extern int main();

void _reset(void);
void _Vector_deafultHandler(void);

void _Vector_NMI(void) 			__attribute__((weak,alias("_Vector_deafultHandler")));
void _Vector_HardFault(void) 	__attribute__((weak,alias("_Vector_deafultHandler")));
void _Vector_MemManage(void) 	__attribute__((weak,alias("_Vector_deafultHandler")));
void _Vector_BusFault(void) 	__attribute__((weak,alias("_Vector_deafultHandler")));
void _Vector_UsageFault(void) 	__attribute__((weak,alias("_Vector_deafultHandler")));

static unsigned int _vector_table[] __attribute__((section(".vectors"))) = {
	(unsigned int)(&_STACK_TOP),
	(unsigned int)(&_Vector_NMI),
	(unsigned int)(&_Vector_HardFault),
	(unsigned int)(&_Vector_MemManage),
	(unsigned int)(&_Vector_BusFault),
	(unsigned int)(&_Vector_UsageFault)
};


void _reset(void){
	unsigned int i,length;
	unsigned char *p_src, * p_dst;

	//init bss section with zeros
	length = (unsigned char*)&_BSS_END - (unsigned char*)&_BSS_START;
	p_dst  = (unsigned char*)&_BSS_START;

	for(i=0;i<length;i++){
		*p_dst = (unsigned char)0;
		p_dst++;
	}


	//copy data section from flash to ram
	length = (unsigned char*)&_DATA_END - (unsigned char*)&_DATA_START;
	p_src  = (unsigned char*)&_RODATA_END;
	p_dst  = (unsigned char*)&_DATA_START;

	for(i=0;i<length;i++){
		*p_dst = (unsigned char) (*p_src);
		p_src++;
		p_dst++;


	}

	//jump to main
	main();

	//superloop
	while( (volatile int)1 );
}

void _Vector_deafultHandler(void){
	_reset();
}

