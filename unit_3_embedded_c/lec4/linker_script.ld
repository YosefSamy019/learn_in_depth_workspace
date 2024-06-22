/* @Youssef Samy Youssef */

MEMORY
{
	flash(RX): ORIGIN = 0x00000000, LENGTH = 512M
	sram(RWX):  ORIGIN = 0x20000000, LENGTH = 512M
}

SECTIONS
{

	. = 0x00000000;

	.text : 
	{
		_S_TEXT = .;
		*(.vectors*)
		*(.text*)
		*(.rodata*)
		. = ALIGN(4);
		_E_TEXT = .;

	}> flash

	.data : 
	{
		_S_DATA = .;
		*(.data)
		. = ALIGN(4);
		_E_DATA = .;
	}> sram AT> flash


	.bss : 
	{
		_S_BSS = .;
		*(.bss*)
		. = ALIGN(4);
		_E_BSS = .;
	}> sram
}