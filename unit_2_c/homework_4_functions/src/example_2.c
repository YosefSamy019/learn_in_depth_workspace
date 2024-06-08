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

unsigned long long fact(int num) {
	if (num <= 1)
		return 1;
	else
		return num * fact(num - 1);
}

int ex2(void) {
	int num;

	printf("Enter a number: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%d", &num);

	if (num < 0) {
		printf("Negative number\n");
	} else {
		printf("Result is: %u", fact(num));
	}

	return 0;
}
