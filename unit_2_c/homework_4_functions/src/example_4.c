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
#include <string.h>

int power(int num, int p) {
	if (p == 0)
		return 1;
	return num * power(num, p - 1);
}

int ex4(void) {
	int num;
	int p;

	printf("Enter base num: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%d", &num);

	printf("Enter positive int power: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%d", &p);

	printf("%d^%d = %d", num, p, power(num, p));

	return 0;
}
