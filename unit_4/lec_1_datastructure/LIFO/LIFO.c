
#include "LIFO.h"

#define NULL ((void*)0)

LIFO_state LIFO_init(LIFO_buf_t* lBuf, ELEMENT_TYPE *base,unsigned int capacity)
{
    lBuf -> capacity = capacity;
    lBuf -> count = 0;
    lBuf -> base = base;
    lBuf -> head = base;

    if(base == NULL)
    {
        return LIFO_Null;
    }
    else
    {
        return LIFO_Ok;
    }
}

LIFO_state LIFO_push(LIFO_buf_t* lBuf,ELEMENT_TYPE  item)
{
    if(lBuf->base == NULL || lBuf->head == NULL)
    {
        return LIFO_Null;
    }
    else if(LIFO_isFull(lBuf) == LIFO_Totally_Full)
    {
        return LIFO_Totally_Full;
    }
    else
    {
        *(lBuf->head) = item;
        lBuf->head++;
        lBuf->count++;
        return LIFO_Ok;
    }
}


LIFO_state LIFO_pop (LIFO_buf_t* lBuf,ELEMENT_TYPE *item)
{
    if(lBuf->base == NULL || lBuf->head == NULL)
    {
        return LIFO_Null;
    }
    else if(LIFO_isFull(lBuf) == LIFO_Empty)
    {
        return LIFO_Empty;
    }
    else
    {
        lBuf->head--;
        lBuf->count--;
        *item = *(lBuf->head);
        return LIFO_Ok;
    }
}

LIFO_state LIFO_isFull(LIFO_buf_t* lBuf)
{
    if(lBuf->base == NULL || lBuf->head == NULL)
    {
        return LIFO_Null;
    }
    else if( (unsigned int)(lBuf->head - lBuf->base) >= lBuf->capacity )
    {
        return LIFO_Totally_Full;
    }
    else if(lBuf->count == 0 || lBuf->base==lBuf->head)
    {
        return LIFO_Empty;
    }

    else
    {
        return LIFO_Partially_Full;
    }
}
