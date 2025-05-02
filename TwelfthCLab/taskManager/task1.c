/*1. Создать очередь для целых чисел. Максимальный размер очереди вводится с экрана. Создать
функции для ввода и вывода элементов очереди. Ввести в очередь числа с экрана. После этого перейти
в режим, при котором при каждом вводе числа выводится первый элемент очереди, и если он не
совпадает с введенным числом, то оно заносится в очередь.*/

#include "../inputManager/getInt.h"
#include "../queueManager/queueManager.h"
#include <stdio.h>
#include <stdlib.h>

void compareElements(Queue_t* queue)
{
    printf("Enter number (101 to exit).");
    int current_num = inputIntInRange(-100, 101);

    while (current_num != 101)
    {
        printf("The first queue element is %d\n", queue -> head -> data);
        if (queue -> head -> data != current_num)
        {
            if (push(queue, current_num) == NULL)
            {
                printf("Your queue is:\n");
                printQueue(queue);
                printf("Queue is full.\n");
                return;
            }

            printf("Your queue is:\n");
            printQueue(queue);
        }
        printf("Enter number (101 to exit).");
        current_num = inputIntInRange(-100, 101);
    }
}


int addNumbers()
{
    printf("Enter queue size in range from 1 to 100.\n");
    const int queue_size = inputIntInRange(1, 100);

    Queue_t *queue = createQueue(queue_size);
    fillQueue(queue);

    compareElements(queue);

    freeQueue(queue);

    return 0;
}