/*
 * ex_1.c
 *
 *  Created on: May 30, 2024
 *      Author: asus
 */



#include <stdio.h>

struct SStudent{
	char name[20];
	int rollNo;
	float marks;
};

void ex_1(){
	struct SStudent s;
	fflush(stdin);
	fflush(stdout);

	printf("Enter inforamtion of students: \n");

	printf("Enter Name: ");
	fflush(stdin);
	fflush(stdout);
	gets(s.name);

	printf("Enter roll number: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%d",&s.rollNo);

	printf("Enter Marks: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%f",&s.marks);

	printf("\Display inforamtion \n");

	printf("Name: %s\n",s.name);
	printf("Roll: %d\n",s.rollNo);
	printf("Marks: %f\n",s.marks);

}
