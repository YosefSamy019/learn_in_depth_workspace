/*
 * ex_2.c
 *
 *  Created on: Jun 3, 2024
 *      Author: asus
 */

#include<stdio.h>

void ex_2() {
	const char A = 'A';
	const char *ptr = &A;

	printf(" The Alphabets are :\n");

	int i;
	for(i=0; *ptr + i <='Z' ; i++){
		printf("%c ",*ptr + i);
	}
}
