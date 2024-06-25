#ifndef FIFO_H_INCLUDED
#define FIFO_H_INCLUDED

#define ELEMENT_TYPE char

typedef struct
{
    ELEMENT_TYPE *base;
    ELEMENT_TYPE *head;
    ELEMENT_TYPE *tail;
    unsigned int count;
    unsigned int capacity;
} FIFO_buf_t;

typedef enum
{
    FIFO_Null,
    FIFO_Totally_Full,
    FIFO_Partially_Full,
    FIFO_Empty,
    FIFO_Ok,
} FIFO_state;

FIFO_state FIFO_init(FIFO_buf_t* fBuf, ELEMENT_TYPE *base,unsigned int capacity);
FIFO_state FIFO_enqueue(FIFO_buf_t* fBuf,ELEMENT_TYPE  item);
FIFO_state FIFO_dequque (FIFO_buf_t* fBuf,ELEMENT_TYPE *item);
FIFO_state FIFO_isFull(FIFO_buf_t* fBuf);

#endif // FIFO_H_INCLUDED
