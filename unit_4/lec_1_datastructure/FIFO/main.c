#include <stdio.h>
#include <stdlib.h>

#include "FIFO.h"

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
    FIFO_state bufState;
    unsigned int i;

    FIFO_buf_t buf1;

    //static
    char arr1[6];
    bufState = FIFO_init(&buf1,&arr1,6);
    printf("Static alloc, init state: %d\n\n",bufState);

    for(i=0; i<10; i++)
    {
        bufState = FIFO_enqueue(&buf1,'a'+i);
        if(bufState == FIFO_Ok)printf("enqueue \'%c\' to FIFO, state %d -> ok\n",'a'+i,bufState);
        if(bufState == FIFO_Totally_Full)printf("enqueue \'%c\' to FIFO, state %d -> full\n",'a'+i,bufState);
    }
    printf("\n");

    for(i=0; i<10; i++)
    {
        char item;
        bufState = FIFO_dequque(&buf1,&item);
        if(bufState == FIFO_Ok)printf("dequque \'%c\' to FIFO, state %d -> ok\n",item,bufState);
        if(bufState == FIFO_Empty)printf("dequque from FIFO failed, state %d -> Empty\n",bufState);
    }
    printf("done \n");

}
void dynamic_alloc()
{
    FIFO_state bufState;
    unsigned int i;

    FIFO_buf_t buf1;

    //dynamic
    char *arr1 =(char*)malloc( sizeof(char) * 6);
    bufState = FIFO_init(&buf1,&arr1,6);

    printf("dynamic alloc, init state: %d\n",bufState);

    for(i=0; i<10; i++)
    {
        bufState = FIFO_enqueue(&buf1,'a'+i);
        if(bufState == FIFO_Ok)printf("enqueue \'%c\' to FIFO, state %d -> ok\n",'a'+i,bufState);
        if(bufState == FIFO_Totally_Full)printf("enqueue \'%c\' to FIFO, state %d -> full\n",'a'+i,bufState);
    }
    printf("\n");

    for(i=0; i<10; i++)
    {
        char item;
        bufState = FIFO_dequque(&buf1,&item);
        if(bufState == FIFO_Ok)printf("dequque \'%c\' to FIFO, state %d -> ok\n",item,bufState);
        if(bufState == FIFO_Empty)printf("dequque from FIFO failed, state %d -> Empty\n",bufState);
    }
    printf("done \n");
}


