/* @Youssef Samy Youssef */

MEMORY
{
	flash(RX): ORIGIN = 0x08000000, LENGTH = 128k
	ram(RWX):  ORIGIN = 0x20000000, LENGTH = 20k
}

SECTIONS
{

	. = 0x08000000;

	.text : 
	{
		_S_TEXT = .;
		*(.vectors*)
		*(.text*)
		. = ALIGN(4);
		_E_TEXT = .;

	}> flash

	.data : 
	{
		_S_DATA = .;
		*(.data)
		. = ALIGN(4);
		_E_DATA = .;
	}> ram AT> flash


	.bss : 
	{
		_S_BSS = .;
		*(.bss*)
		. = ALIGN(4);
		_E_BSS = .;
	}> ram



	. = . + 0x1000;
	stack_top = .;
}