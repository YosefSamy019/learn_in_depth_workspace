/*
 * main.c
 *
 *  Created on: Apr 15, 2024
 *      Author: asus
 */

#include <stdio.h>

void main() {
	int no = 0;

	printf("Enter Example No: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%d", &no);

	switch (no) {
	case 1: {
		printf("C Programming");
		break;
	}
	case 2: {
		int number;

		printf("Enter an Integer: ");
		fflush(stdin);
		fflush(stdout);
		scanf("%d", &number);

		printf("You Entered %d", number);
		break;
	}
	case 3: {
		int num1, num2;

		printf("Enter two Integer: ");
		fflush(stdin);
		fflush(stdout);
		scanf("%d%d", &num1, &num2);

		printf("Sum: %d", num1 + num2);
		break;
	}
	case 4: {
		float num1, num2;

		printf("Enter two float: ");
		fflush(stdin);
		fflush(stdout);
		scanf("%f%f", &num1, &num2);

		printf("Product: %f", num1 * num2);
		break;
	}
	case 5: {
		char c;

		printf("Enter a character: ");
		fflush(stdin);
		fflush(stdout);
		scanf("%c", &c);

		printf("ASCII Value: %d", c);
		break;
	}
	case 6: {
		float a, b, temp;

		printf("Enter a: ");
		fflush(stdin);
		fflush(stdout);
		scanf("%f", &a);

		printf("Enter b: ");
		fflush(stdin);
		fflush(stdout);
		scanf("%f", &b);

		temp = a;
		a = b;
		b = temp;

		printf("After Swapping, a = %f\n", a);
		printf("After Swapping, b = %f\n", b);

		break;
	}
	case 7: {
		float a, b;

		printf("Enter a: ");
		fflush(stdin);
		fflush(stdout);
		scanf("%f", &a);

		printf("Enter b: ");
		fflush(stdin);
		fflush(stdout);
		scanf("%f", &b);

		a = a + b;
		b = a - b;
		a = a - b;

		printf("After Swapping, a = %f\n", a);
		printf("After Swapping, b = %f\n", b);

		break;
	}
	}
}

