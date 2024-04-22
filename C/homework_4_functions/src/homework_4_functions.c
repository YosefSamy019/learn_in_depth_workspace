/*
 ============================================================================
 Name        : homework_4_functions.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>

int ex1(void);
int ex2(void);
int ex3(void);
int ex4(void);

int main(void) {
	int no = 0;

	printf("Enter Example No: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%d", &no);

	switch (no) {
	case 1:
		ex1();
		break;
	case 2:
		ex2();
		break;
	case 3:
		ex3();
		break;
	case 4:
		ex4();
		break;

	}
	return 0;
}
