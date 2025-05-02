/*2. Создать дек для целых чисел. Максимальный размер дека вводится с экрана. Создать
функции для ввода и вывода элементов дека. Ввести в дек числа с экрана. После этого перейти в
режим, при котором из начала удаляется элемент, и если он совпадает с введенным числом, то введенное
число добавляется в конец, а иначе в начало.*/

#include <stdio.h>
#include "../dequeManager/dequeManager.h"
#include "../inputManager/getInt.h"


void deleteHeadAndAdd(Deque_t* deque)
{
    printf("\nEnter number in range from -100 to 100 (101 to exit)\n");
    int current_num = inputIntInRange(-100, 101);

    while (current_num != 101)
    {
        const int head_num = deque -> head -> data;
        printf("The first number in deque is: %d.\n", head_num);

        deque = popHead(deque);

        if (head_num == current_num)
        {
            pushTail(deque, current_num);
        }
        else
        {
            pushHead(deque, current_num);
        }

        printf("Your deque is:\n");
        printDeque(deque);

        printf("\nEnter number in range from -100 to 100 (101 to exit).\n");
        current_num = inputIntInRange(-100, 101);
    }
}

void deleteHeadAndAddElement()
{
    Deque_t* deque = createDeque();
    deque = fillDeque(deque);

    printf("Your deque is:\n");
    printDeque(deque);

    deleteHeadAndAdd(deque);

    freeDeque(deque);
}
