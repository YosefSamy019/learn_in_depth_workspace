/* @Youssef Samy Youssef */

.section .vectors

	.word stack_top 			/*Stack top*/
	.word _reset
	.word _default_handler
	.word _default_handler
	.word _default_handler
	.word _default_handler
	.word _default_handler
	.word _default_handler
	.word _default_handler
	.word _default_handler
	.word _default_handler
	.word _default_handler
	.word _default_handler
	.word _default_handler
	.word _default_handler
	.word _default_handler
	.word _default_handler
	.word _default_handler
	.word _default_handler
	.word _default_handler


.section .text
	_reset:
		bl main
		STOP: b STOP

	.thumb_func

	_default_handler:
		bl _reset