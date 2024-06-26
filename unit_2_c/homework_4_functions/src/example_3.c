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

void reverse(char* ptr, int size) {
	if (size < 1)
		return;


	//swap
	char temp = ptr[0];
	ptr[0] = ptr[size - 1];
	ptr[size - 1] = temp;

	reverse(ptr + 1, size - 2);
}

int ex3(void) {
	char num[20];

	printf("Enter a string: ");
	fflush(stdin);
	fflush(stdout);
	gets(num);

	reverse(num, strlen(num));

	puts(num);

	return 0;
}
