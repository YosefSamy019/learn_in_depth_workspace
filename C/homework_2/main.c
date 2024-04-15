/*
 * main.c
 *
 *  Created on: Apr 15, 2024
 *      Author: asus
 */

#include <stdio.h>

void ex1();
void ex2();
void ex3();
void ex4();
void ex5();
void ex6();
void ex7();
void ex8();

void main() {
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
	case 5:
		ex5();
		break;
	case 6:
		ex6();
		break;
	case 7:
		ex7();
		break;
	case 8:
		ex8();
		break;
	}
}

void ex1() {
	int num;

	printf("Enter Number: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%d", &num);

	if ((num & 1) == 0) {
		printf("%d is Even\n", num);
	} else {
		printf("%d is Odd\n", num);
	}

}

void ex2() {
	char c, flag = 0;

	printf("Enter an alphapet: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%c", &c);

	flag = (c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') || (c == 'u')
			|| (c == 'A') || (c == 'E') || (c == 'I') || (c == 'O')
			|| (c == 'U');

	if (flag) {
		printf("%c is vowel\n", c);
	} else {
		printf("%c is consonant\n", c);
	}
}

void ex3() {
	float n1, n2, n3;
	float max;

	printf("Enter 3 Numbers: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%f%f%f", &n1, &n2, &n3);

	max = n1;
	if (max < n2)
		max = n2;
	if (max < n3)
		max = n3;

	printf("Large Number: %f", max);
}

void ex4() {
	int num;

	printf("Enter Number: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%d", &num);

	if (num == 0) {
		printf("You entered Zero\n");
	} else if (num < 0) {
		printf("%d is negative\n", num);
	} else {
		printf("%d is positive\n", num);
	}
}

void ex5() {
	char c;

	printf("Enter character: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%c", &c);

	if ((c <= 'z' && c >= 'a') || (c <= 'Z' && c >= 'A')) {
		printf("%c is alphapet\n", c);
	} else {
		printf("%c is not alphapet\n", c);
	}
}

void ex6() {
	int num;
	long long res;

	printf("Enter Number: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%d", &num);

	res = (long long) (num * (num + 1) * 0.5);

	printf("sum: %d", res);
}

void ex7() {
	int num;
	unsigned int i;
	long long res;

	printf("Enter Number: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%d", &num);

	if (num >= 0) {
		res = 1;
		for (i = 2; i <= num; i++) {
			res = res * i;
		}

		printf("fact: %d", res);
	} else {
		printf("Negative numbers has no fact\n");
	}
}

void ex8() {
	float n1, n2, res;
	char op;

	printf("Enter operator (+ - * /): ");
	fflush(stdin);
	fflush(stdout);
	scanf("%c", &op);

	if (op == '+' || op == '-' || op == '*' || op == '/') {

		printf("Enter 2 numbers: ");
		fflush(stdin);
		fflush(stdout);
		scanf("%f%f", &n1, &n2);

		switch (op) {
		case '+':
			res = n1 + n2;
			break;
		case '-':
			res = n1 - n2;
			break;
		case '*':
			res = n1 * n2;
			break;
		case '/':
			res = n1 / n2;
			break;
		}

		printf("%f %c %f = %f", n1, op, n2, res);

	} else {
		printf("wrong input\n");
	}
}
