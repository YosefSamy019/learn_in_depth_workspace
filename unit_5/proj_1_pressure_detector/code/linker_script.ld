/*
	@Youssef Samy Youssef
	Linker Script, Arm Cortex m3
*/




MEMORY{
	flash(rx) : ORIGIN = 0x08000000, LENGTH = 128k
	sram(rwx) : ORIGIN  = 0x20000000, LENGTH =  20k
}


SECTIONS{
	
	. = 0x08000000;

	.text : 
	{
		_TEXT_START = .;

		*(.vectors*)
		*(.text*)

		. = ALIGN(4);
		_TEXT_END = .;


	}> flash

	.rodata :
	{
		_RODATA_START = .;

		*(.rodata*)

		. = ALIGN(4);
		_RODATA_END = .;

	}> flash

	.data :
	{
		_DATA_START = .;

		*(.data*)

		. = ALIGN(4);
		_DATA_END = .;

	}> sram AT> flash

	.bss :
	{
		_BSS_START = .;

		*(.bss*)
		*(COMMON)

		. = ALIGN(4);
		_BSS_END = .;

		. = . + 0x1000;
		_STACK_TOP = .;
	}> sram
}