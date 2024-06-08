/*
 * main.c
 *
 *  Created on: Jun 3, 2024
 *      Author: asus
 */

#include<stdio.h>

void ex_1();
void ex_2();
void ex_3();
void ex_4();
void ex_5();

void main() {
	int no = 0;

	printf("Enter Example No: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%d", &no);

	switch (no) {
	case 1:
		ex_1();
		break;
	case 2:
		ex_2();
		break;
	case 3:
		ex_3();
		break;
	case 4:
		ex_4();
		break;
	case 5:
		ex_5();
		break;
	}
}

