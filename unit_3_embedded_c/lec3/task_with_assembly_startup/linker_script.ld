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
		*(.vectors*)
		*(.text*)
	}> flash

	.bss : 
	{
		*(.bss*)
	}> ram

	. = . + 0x1000;
	stack_top = .;
}