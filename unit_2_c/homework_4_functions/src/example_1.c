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
char isPrime(int num) {
	char flag = 1;

	if (num <= 2)
		flag = 0;
	else {
		int i = 2;
		for (; (i * i) <= num; i++) {
			if (num % i == 0) {
				flag = 0;
				break;
			}
		}
	}

	return flag;
}

int ex1(void) {
	int min, max, i;
	char found = 0;

	printf("Enter 2 numbers (intervals): ");
	fflush(stdin);
	fflush(stdout);
	scanf("%d %d", &min, &max);

	for (i = min; i <= max; i++) {
		if (isPrime(i)) {
			found = 1;
			printf("%d ", i);
		}
	}

	if (found == 0) {
		printf("No number found\n");
	}

	return 0;
}
