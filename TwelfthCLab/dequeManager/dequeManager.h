#ifndef DEQUEMANAGER_H
#define DEQUEMANAGER_H


typedef struct DNode
{
    int data;
    struct DNode * next;
    struct DNode * prev;
}DNode_t;

typedef struct
{
    DNode_t* head;
    DNode_t* tail;
}Deque_t;

Deque_t* createDeque();

void pushHead(Deque_t* deque, int data);

void pushTail(Deque_t* deque, int data);

Deque_t* popHead(Deque_t* deque);

Deque_t* fillDeque(Deque_t* deque);

void printDeque(const Deque_t* deque);

void freeDeque(Deque_t* deque);

#endif
