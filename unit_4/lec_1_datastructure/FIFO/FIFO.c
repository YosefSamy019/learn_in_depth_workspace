#include "FIFO.h"
#define NULL ((void*)0)

FIFO_state FIFO_init(FIFO_buf_t* fBuf, ELEMENT_TYPE *base,unsigned int capacity)
{

    fBuf -> capacity = capacity;
    fBuf -> count = 0;
    fBuf -> base = base;
    fBuf -> head = base;
    fBuf -> tail = base;

    if(base == NULL)
    {
        return FIFO_Null;
    }
    else
    {
        return FIFO_Ok;
    }
}

FIFO_state FIFO_enqueue(FIFO_buf_t* fBuf,ELEMENT_TYPE  item)
{
    if(FIFO_isFull(fBuf) == FIFO_Null)
    {
        return FIFO_Null;
    }
    else if(FIFO_isFull(fBuf) == FIFO_Totally_Full)
    {
        return FIFO_Totally_Full;
    }
    else
    {
        *(fBuf->head) = item;

        fBuf->count++;
        //circular
        if( fBuf->head == fBuf->base + (fBuf->capacity) * sizeof(ELEMENT_TYPE) )
        {
            fBuf->head = fBuf->base;
        }
        else
        {
            (fBuf->head)++;
        }

        return FIFO_Ok;

    }

}

FIFO_state FIFO_dequque (FIFO_buf_t* fBuf,ELEMENT_TYPE *item)
{
    if(FIFO_isFull(fBuf) == FIFO_Null)
    {
        return FIFO_Null;
    }
    else if(FIFO_isFull(fBuf) == FIFO_Empty)
    {
        return FIFO_Empty;
    }
    else
    {
        *item =  *(fBuf->tail);

        fBuf->count--;
        //circular
        if( fBuf->tail == fBuf->base + (fBuf->capacity) * sizeof(ELEMENT_TYPE) )
        {
            fBuf->tail = fBuf->base;
        }
        else
        {
            fBuf->tail++;
        }

        return FIFO_Ok;

    }
}

FIFO_state FIFO_isFull(FIFO_buf_t* fBuf)
{
    if(fBuf->base == NULL || fBuf->head == NULL || fBuf->tail ==NULL)
    {
        return FIFO_Null;
    }
    else if( fBuf->count == fBuf->capacity)
    {
        return FIFO_Totally_Full;
    }
    else if(fBuf->count == 0)
    {
        return FIFO_Empty;
    }

    else
    {
        return FIFO_Partially_Full;
    }

}
