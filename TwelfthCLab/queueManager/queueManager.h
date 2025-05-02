#ifndef QUEUEMANAGER_H
#define QUEUEMANAGER_H


typedef struct Node
{
    int data;
    struct Node* next;
}Node_t;

typedef struct
{
    Node_t* head;
    Node_t* tail;
    int available_size;
} Queue_t;

Queue_t* createQueue(int queue_size);

Queue_t* push(Queue_t* queue, int data);

Queue_t* pop(Queue_t* queue);

void freeQueue(Queue_t* queue);

void printQueue(const Queue_t* queue);

Queue_t* fillQueue(Queue_t* queue);


#endif
