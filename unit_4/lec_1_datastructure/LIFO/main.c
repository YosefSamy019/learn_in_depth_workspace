#include <stdio.h>
#include <stdlib.h>

#include "LIFO.h"

void static_alloc();
void dynamic_alloc();

int main()
{
    static_alloc();
    printf("\n");
    dynamic_alloc();
    return 0;
}

void static_alloc()
{
    LIFO_state bufState;
    unsigned int i;

    LIFO_buf_t buf1;

    //static
    char arr1[6];
    bufState = LIFO_init(&buf1,&arr1,6);
    printf("Static alloc, init state: %d\n\n",bufState);

    for(i=0; i<10; i++)
    {
        bufState = LIFO_push(&buf1,'a'+i);
        if(bufState == LIFO_Ok)printf("Push \'%c\' to LIFO, state %d -> ok\n",'a'+i,bufState);
        if(bufState == LIFO_Totally_Full)printf("Push \'%c\' to LIFO, state %d -> full\n",'a'+i,bufState);
    }
    printf("\n");

    for(i=0; i<10; i++)
    {
        char item;
        bufState = LIFO_pop(&buf1,&item);
        if(bufState == LIFO_Ok)printf("Pop \'%c\' to LIFO, state %d -> ok\n",item,bufState);
        if(bufState == LIFO_Empty)printf("Pop from LIFO failed, state %d -> Empty\n",bufState);
    }
    printf("\n");

}
void dynamic_alloc()
{
    LIFO_state bufState;
    unsigned int i;

    LIFO_buf_t buf1;

    //dynamic
    char *arr1 =(char*)malloc( sizeof(char) * 6);
    bufState = LIFO_init(&buf1,&arr1,6);

    printf("dynamic alloc, init state: %d\n",bufState);

    for(i=0; i<10; i++)
    {
        bufState = LIFO_push(&buf1,'A'+i);
        if(bufState == LIFO_Ok)printf("Push \'%c\' to LIFO, state %d -> ok\n",'A'+i,bufState);
        if(bufState == LIFO_Totally_Full)printf("Push \'%c\' to LIFO, state %d -> full\n",'A'+i,bufState);
    }
    printf("\n");

    for(i=0; i<10; i++)
    {
        char item;
        bufState = LIFO_pop(&buf1,&item);
        if(bufState == LIFO_Ok)printf("Pop \'%c\' to LIFO, state %d -> ok\n",item,bufState);
        if(bufState == LIFO_Empty)printf("Pop from LIFO failed, state %d -> Empty\n",bufState);
    }
    printf("\n");
}


