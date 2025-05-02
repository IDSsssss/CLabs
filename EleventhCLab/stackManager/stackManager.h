#ifndef STACKMANAGER_H
#define STACKMANAGER_H


typedef struct obj_t
{
    int data;
    struct obj_t* next;
}Stack;

Stack* push(Stack* top, int data);

Stack* pop(Stack* top);

void printStack(const Stack* top);

Stack* fillStack(Stack* top);

Stack* fillStackAscending(Stack* top);

int addEven(const Stack* top);

Stack* merge(const Stack* top_1, const Stack* top_2);

void freeStack(Stack* top);


#endif
