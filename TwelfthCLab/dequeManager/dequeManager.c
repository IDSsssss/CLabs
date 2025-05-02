#include "dequeManager.h"
#include "../memoryManager/memoryManager.h"
#include "../inputManager/getInt.h"
#include <stdio.h>
#include <stdlib.h>


Deque_t* createDeque()
{
	Deque_t* deque = safeMalloc(sizeof(Deque_t));
    deque -> head = NULL;
    deque -> tail = NULL;

    return deque;
}


void pushHead(Deque_t* deque, const int data)
{
    DNode_t* new_d_node = safeMalloc(sizeof(DNode_t));

    new_d_node -> data = data;
    new_d_node -> prev = NULL;
    new_d_node -> next = deque -> head;

    if (deque -> head == NULL)
    {
        deque -> head = new_d_node;
        deque -> tail = new_d_node;
    }
    else
    {
        deque -> head -> prev = new_d_node;
        deque -> head = new_d_node;
    }
}


void pushTail(Deque_t* deque, const int data)
{
    DNode_t* new_d_node = safeMalloc(sizeof(DNode_t));

    new_d_node -> data = data;
    new_d_node -> next = NULL;
    new_d_node -> prev = deque->tail;

    if (deque -> head == NULL)
    {
        deque -> head = new_d_node;
        deque -> tail = new_d_node;
    }

    else
    {
        deque -> tail -> next = new_d_node;
        deque -> tail = new_d_node;
    }
}


Deque_t* popHead(Deque_t* deque)
{
    if (deque -> head == NULL)
    {
        return NULL;
    }

    DNode_t* node = deque->head;
    deque -> head = deque -> head -> next;

    free(node);

    if (deque -> head == NULL)
    {
        deque -> tail = NULL;
    }
    else
    {
        deque -> head -> prev = NULL;
    }
    return deque;
}


Deque_t* fillDeque(Deque_t* deque)
{
    printf("Enter the number of deque elements in range from 1 to 100.\n");
    const int size = inputIntInRange(1, 100);

    for (int i = 0; i < size; ++i)
    {
        printf("Enter %d element.\n", i + 1);
        pushTail(deque, inputIntInRange(-100, 100));
    }

    return deque;
}

void printDeque(const Deque_t* deque)
{
    const DNode_t* current_node = deque -> head;

    while (current_node != NULL)
    {
        printf("    %d\n", current_node -> data);
        current_node = current_node -> next;
    }
}


void freeDeque(Deque_t* deque)
{
    DNode_t* current = deque -> head;

    while (current != NULL)
    {
        DNode_t *next = current -> next;

        free(current);

        current = next;
    }
    free(deque);
}