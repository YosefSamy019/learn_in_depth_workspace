/*
 * ex_1.c
 *
 *  Created on: May 30, 2024
 *      Author: asus
 */



#include <stdio.h>

#define LEN 10

struct SStudent{
	char name[20];
	int rollNo;
	float marks;
};

void ex_4(){
	struct SStudent s[LEN];

	fflush(stdin);
	fflush(stdout);

	printf("Enter inforamtion of students: \n");

	int i;
	for(i=0;i<LEN;i++){

		printf("For roll number %d \nEnter Name: ",i+1);
		fflush(stdin);
		fflush(stdout);
		gets(s[i].name);

		printf("Enter roll number: ");
		fflush(stdin);
		fflush(stdout);
		scanf("%d",&s[i].rollNo);

		printf("Enter Marks: ");
		fflush(stdin);
		fflush(stdout);
		scanf("%f",&s[i].marks);

	}

	printf("\Display inforamtion \n");

	for(i=0;i<LEN;i++){
		printf("Information for roll number %d \nName: %s\n",i+1,s[i].name);
		printf("Roll: %d\n",s[i].rollNo);
		printf("Marks: %f\n",s[i].marks);
	}

}
