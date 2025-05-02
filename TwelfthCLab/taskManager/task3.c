/*3. Найдите среди трех (4,5) очередей две одинаковые. Решение в программе оформляйте через
подпрограммы.*/

#include "../queueManager/queueManager.h"
#include "../inputManager/getInt.h"
#include "../memoryManager/memoryManager.h"

#include <stdio.h>
#include <stdlib.h>


Queue_t** createAndFillQueuesArray(const int queues_count)
{
    Queue_t** queues = safeMalloc(sizeof(Queue_t*) * queues_count);

    for (int i = 0; i < queues_count; ++i)
    {
        puts("");

        queues[i] = createQueue(100);
        queues[i] = fillQueue(queues[i]);

        printf("\nThe %d queue is:\n", i + 1);
        printQueue(queues[i]);
    }

    return queues;
}


int compareTwoQueues(const Queue_t* queue_1, const Queue_t* queue_2, const int first_queue_number, const int second_queue_number)
{
    const Node_t* current_1_node = queue_1 -> head;
    const Node_t* current_2_node = queue_2 -> head;

    while (current_1_node != NULL && current_2_node != NULL)
    {

        current_1_node = current_1_node -> next;
        current_2_node = current_2_node -> next;
    }

    if (current_2_node == NULL && current_1_node == NULL)
    {
        printf("\nQueues %d and %d are equal.\n", first_queue_number, second_queue_number);
        return 1;
    }

    return 0;
}


void compare(const int queues_count, Queue_t** queues)
{
    int counter = 0;

    for (int i = 0; i < queues_count; ++i)
    {
        for (int j = i + 1; j < queues_count; ++j)
        {
            if (compareTwoQueues(queues[i], queues[j], i + 1, j + 1))
            {
                ++counter;
            }
        }
    }

    if (counter == 0)
    {
        printf("\nThere are no equal queues.\n");
    }
}


void freeQueuesArray(Queue_t** queues, const int queues_count)
{
    for (int i = 0; i < queues_count; ++i)
    {
        free(queues[i]);
    }

    free(queues);
}


void compareQueues()
{
    printf("Enter queues count in range from 1 to 5.\n");
    const int queues_count = inputIntInRange(1, 5);

    Queue_t** queues = createAndFillQueuesArray(queues_count);

    compare(queues_count, queues);

    freeQueuesArray(queues, queues_count);
}