/*
 * main.c
 *
 *  Created on: Apr 16, 2024
 *      Author: asus
 */

#include <stdio.h>

void ex1();
void ex2();
void ex3();
void ex4();
void ex5();

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
	}
}

void ex1() {
	const int SI = 2;

	float arr1[SI][SI];
	float arr2[SI][SI];
	float sum[SI][SI];
	int i, j;

	printf("Enter elements of 1st matrix\n");
	for (i = 0; i < SI; i++) {
		for (j = 0; j < SI; j++) {
			printf("Enter a%d%d: ", i + 1, j + 1);
			fflush(stdin);
			fflush(stdout);
			scanf("%f", &arr1[i][j]);
		}
	}

	printf("Enter elements of 2st matrix\n");
	for (i = 0; i < SI; i++) {
		for (j = 0; j < SI; j++) {
			printf("Enter b%d%d: ", i + 1, j + 1);
			fflush(stdin);
			fflush(stdout);
			scanf("%f", &arr2[i][j]);
		}
	}

	for (i = 0; i < SI; i++) {
		for (j = 0; j < SI; j++) {
			sum[i][j] = arr1[i][j] + arr2[i][j];
		}
	}

	printf("Sum of matrix:\n");
	for (i = 0; i < SI; i++) {
		for (j = 0; j < SI; j++) {
			printf("%f ", sum[i][j]);
		}
		printf("\n");
	}
}

void ex2() {
	unsigned int si, i;
	printf("Enter number of data: ");

	fflush(stdin);
	fflush(stdout);
	scanf("%u", &si);

	float arr[si], sum = 0, avg = 0;

	for (i = 0; i < si; i++) {
		printf("%d Enter number: ", i + 1);

		fflush(stdin);
		fflush(stdout);
		scanf("%f", &arr[i]);
	}

	for (i = 0; i < si; i++) {
		sum += arr[i];
	}

	avg = sum / si;

	printf("Average: %f", avg);
}

void ex3() {
	unsigned int rows, cols, i, j;
	printf("Enter number of rows columns: ");

	fflush(stdin);
	fflush(stdout);
	scanf("%u%u", &rows, &cols);

	int arr[rows][cols];
	int transpose[cols][rows];

	for (i = 0; i < rows; i++) {
		for (j = 0; j < cols; j++) {
			printf("Enter a%d%d: ", i + 1, j + 1);
			fflush(stdin);
			fflush(stdout);
			scanf("%d", &arr[i][j]);
		}
	}

	for (i = 0; i < rows; i++) {
		for (j = 0; j < cols; j++) {
			transpose[j][i] = arr[i][j];
		}
	}

	for (i = 0; i < cols; i++) {
		for (j = 0; j < rows; j++) {
			printf("%d ", transpose[i][j]);
		}
		printf("\n");
	}

}

void ex4() {
	unsigned int si, i, location;
	int insert;

	printf("Enter number of data: ");

	fflush(stdin);
	fflush(stdout);
	scanf("%u", &si);

	int arr[si];

	for (i = 0; i < si; i++) {
		arr[i] = i + 1;
	}

	for (i = 0; i < si; i++) {
		printf("%d ", arr[i]);

	}
	printf("\n");

	printf("Enter element to be inserted: ");

	fflush(stdin);
	fflush(stdout);
	scanf("%d", &insert);

	printf("Enter location: ");

	fflush(stdin);
	fflush(stdout);
	scanf("%u", &location);

	if ((location - 1) < si) {
		arr[location - 1] = insert;
	}

	for (i = 0; i < si; i++) {
		printf("%d ", arr[i]);

	}
	printf("\n");
}

void ex5() {
	unsigned int si, i, flag;
	int target;

	printf("Enter number of data: ");

	fflush(stdin);
	fflush(stdout);
	scanf("%u", &si);

	int arr[si];

	for (i = 0; i < si; i++) {
		arr[i] = (i + 1) * 10 + i + 1;
	}

	for (i = 0; i < si; i++) {
		printf("%d ", arr[i]);

	}
	printf("\n");

	printf("Enter element to be searched: ");

	fflush(stdin);
	fflush(stdout);
	scanf("%d", &target);

	flag = 0;
	for (i = 0; i < si; i++) {
		if (arr[i] == target) {
			printf("Number found at location%d\n", i + 1);
			flag = 1;
		}
	}

	if (flag == 0)
		printf("Not found\n");

}
