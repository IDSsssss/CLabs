#include "queueManager.h"
#include "../memoryManager/memoryManager.h"
#include "../inputManager/getInt.h"
#include <stdio.h>
#include <stdlib.h>

Queue_t* createQueue(const int queue_size)
{
    Queue_t* queue = safeMalloc(sizeof(Queue_t));
    queue -> head = NULL;
    queue -> tail = NULL;
    queue -> available_size = queue_size;

    return queue;
}

Queue_t* push(Queue_t* queue, const int data)
{
    if (queue -> available_size == 0)
    {
        return NULL;
    }

    Node_t* newNode = safeMalloc(sizeof(Node_t));
    newNode -> data = data;
    newNode -> next = NULL;

    if (queue -> tail != NULL)
        queue -> tail -> next = newNode;
    else
        queue -> head = newNode;

    queue -> tail = newNode;
    --queue -> available_size;

    return queue;
}

Queue_t* pop(Queue_t* queue)
{
    if (queue -> head == NULL)
        return NULL;

    Node_t* tempNext = queue -> head -> next;
    free(queue -> head);

    if (tempNext == NULL)
    {
        queue -> head = NULL;
        queue -> tail = NULL;
    }
    else
    {
        queue -> head = tempNext;
    }

    ++queue -> available_size;

    return queue;
}


void freeQueue(Queue_t* queue)
{
    while (queue -> head != NULL)
        queue = pop(queue);

    free(queue);
}


void printQueue(const Queue_t* queue)
{
    const Node_t* currentNode = queue -> head;
    while (currentNode != NULL)
    {
        printf("    %d\n", currentNode -> data);
        currentNode = currentNode -> next;
    }
    printf("\n");
}


Queue_t* fillQueue(Queue_t* queue)
{
    printf("Enter the number of queue elements in range from 1 to %d.\n", queue -> available_size);
    const int size = inputIntInRange(1, queue -> available_size);

    for (int i = 0; i < size; ++i)
    {
        printf("Enter %d element.\n", i + 1);
        if (push(queue, inputIntInRange(-100, 100)) == NULL)
        {
            printf("Queue is full.\n");
            return NULL;
        }
    }

    return queue;
}