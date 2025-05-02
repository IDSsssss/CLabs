#include "stackManager.h"
#include "../inputManager/getInt.h"

#include <stdio.h>
#include <stdlib.h>


Stack* push(Stack* top, const int data)
{
    Stack* ptr = malloc(sizeof(Stack));

    ptr -> data = data;
    ptr -> next = top;

    return ptr;
}


Stack* pop(Stack* top)
{
    if (top == NULL)
    {
        return NULL;
    }

    Stack* ptr = top -> next;

    free(top);

    return ptr;
}


void printStack(const Stack* top)
{
    const Stack* current_ptr = top;
    while (current_ptr != NULL)
    {
        printf("    %d\n", current_ptr -> data);
        current_ptr = current_ptr -> next;
    }
}


Stack* fillStack(Stack* top)
{
    printf("Enter stack size in range from 1 to 100.\n");

    const int size = inputInt();

    for (int i = 0; i < size; ++i)
    {
        printf("Enter %d stack element in range from -100 to 100.\n", i + 1);

        top = push(top, inputIntInRange(-100, 100));
    }

    return top;
}


Stack* fillStackAscending(Stack* top)
{
    printf("Enter stack size in range from 1 to 100.\n");

    const int size = inputInt();

    int max_value = 100;


    for (int i = 0; i < size; ++i)
    {
        printf("Enter %d stack element in range from -100 to %d.\n", i + 1, max_value);
        max_value = inputIntInRange(-100, max_value);

        top = push(top, max_value);
    }

    return top;
}


int addEven(const Stack* top)
{
    const Stack* current_ptr = top;
    int sum = 0;

    while (current_ptr != NULL)
    {
        if (current_ptr -> data % 2 == 0)
        {
            sum += current_ptr -> data;
        }

        current_ptr = current_ptr -> next;
    }

    return sum;
}


Stack* merge(const Stack* top_1, const Stack* top_2)
{
    if (top_1 == top_2)
    {
        return NULL;
    }

    Stack* temp_top = NULL;

    while (top_1 != NULL && top_2 != NULL)
    {
        if (top_1 -> data < top_2 -> data)
        {
            temp_top = push(temp_top, top_1 -> data);
            top_1 = top_1 -> next;
        }
        else
        {
            temp_top = push(temp_top, top_2 -> data);
            top_2 = top_2 -> next;
        }
    }

    if (top_1 == NULL)
    {
        while (top_2 != NULL)
        {
            temp_top = push(temp_top, top_2 -> data);
            top_2 = top_2 -> next;
        }
    }
    else
    {
        while (top_1 != NULL)
        {
            temp_top = push(temp_top, top_1 -> data);
            top_1 = top_1 -> next;
        }
    }

    Stack* top_3 = NULL;

    while (temp_top != NULL)
    {
        top_3 = push(top_3, temp_top -> data);
        temp_top = temp_top -> next;
    }
    free(temp_top);

    return top_3;
}


void freeStack(Stack* top)
{
    while (top != NULL)
    {
        Stack* ptr = top -> next;

        free(top);

        top = ptr;
    }
}