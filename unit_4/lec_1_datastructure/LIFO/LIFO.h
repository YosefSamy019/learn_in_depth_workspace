#ifndef LIFO_H_INCLUDED
#define LIFO_H_INCLUDED

#define ELEMENT_TYPE char

typedef struct
{
    ELEMENT_TYPE *base;
    ELEMENT_TYPE *head;
    unsigned int count;
    unsigned int capacity;
} LIFO_buf_t;

typedef enum
{
    LIFO_Null,
    LIFO_Totally_Full,
    LIFO_Partially_Full,
    LIFO_Empty,
    LIFO_Ok,
}LIFO_state;

LIFO_state LIFO_init(LIFO_buf_t* lBuf, ELEMENT_TYPE *base,unsigned int capacity);
LIFO_state LIFO_push(LIFO_buf_t* lBuf,ELEMENT_TYPE  item);
LIFO_state LIFO_pop (LIFO_buf_t* lBuf,ELEMENT_TYPE *item);
LIFO_state LIFO_isFull(LIFO_buf_t* lBuf);

#endif // LIFO_H_INCLUDED
