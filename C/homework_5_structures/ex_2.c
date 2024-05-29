/*
 * ex_1.c
 *
 *  Created on: May 30, 2024
 *      Author: asus
 */



#include <stdio.h>

struct SDim{
int feet;
	float inch;
} ;

void ex_2(){
	struct SDim d1,d2,sum;


	fflush(stdin);
	fflush(stdout);

	printf("Enter inforamtion of 1st distace: \n");

	printf("Enter feet: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%d",&d1.feet);

	printf("Enter inch: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%f",&d1.inch);

	printf("\nEnter inforamtion of 2nd distace: \n");

	printf("Enter feet: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%d",&d2.feet);

	printf("Enter inch: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%f",&d2.inch);


	sum.feet = d1.feet + d2.feet;
	sum.inch = d1.inch + d2.inch;

	if(sum.inch > 12){
		sum.inch -= 12.0;
		sum.feet++;
	}

	printf("Sum: %d\'- %f \"",sum.feet,sum.inch);

}
