#include<stdio.h>
#include<string.h>

struct SEmployee{
	char name[20];
	int id;
}Alex;

void ex_5(){
	struct SEmployee *ptr = &Alex;


	ptr->id = 1002;
	strcpy(ptr->name,"Alex");

	printf("Name:%s\nId:%d",ptr->name,ptr->id);
}
