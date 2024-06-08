/*
 ============================================================================
 Name        : homework_3_strings.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <string.h>

#define MAX_SI 30

void ex1();
void ex2();
void ex3();

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
	}
	return 0;
}

void ex1() {
	char arr[MAX_SI], c;
	int i, freq = 0;

	printf("Enter String: ");

	fflush(stdin);
	fflush(stdout);
	gets(arr);

	printf("Enter char to find Freq: ");

	fflush(stdin);
	fflush(stdout);
	scanf("%c", &c);

	for (i = 0; i < MAX_SI && arr[i] != 0; i++) {
		if (arr[i] == c) {
			freq++;
		}
	}

	printf("Freq = %d\n", freq);
}

void ex2() {
	char arr[MAX_SI];
	int i;

	printf("Enter String: ");

	fflush(stdin);
	fflush(stdout);
	gets(arr);

	for (i = 0; arr[i] != 0; i++)
		;

	printf("Len: %d\n", i);
}

void ex3() {
	char arr[MAX_SI];
	int length, i;
	char temp;

	printf("Enter String: ");

	fflush(stdin);
	fflush(stdout);
	gets(arr);

	length = strlen(arr);

	for (i = 0; i < length / 2; i++) {
		//swap
		temp = arr[i];
		arr[i] = arr[length - i - 1];
		arr[length - i - 1] = temp;
	}

	printf("Result: %s", arr);

}
