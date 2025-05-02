/*2. Создать два стека для целых чисел. Первый стек – организовать ввод по возрастанию,
второй стек – организовать ввод по возрастанию. Без сортировок и переворачивания
исходных стеков сформировать третий стек упорядоченный по возрастанию*/

#include "../stackManager/stackManager.h"

#include <stdio.h>


void mergeStacks()
{
    Stack* top_1 = NULL;
    top_1 = fillStackAscending(top_1);
    printf("\nThe first stack is:\n");
    printStack(top_1);

    Stack* top_2 = NULL;
    top_2 = fillStackAscending(top_2);
    printf("\nThe second stack is:\n");
    printStack(top_2);

    Stack* top_3 = merge(top_1, top_2);
    printf("\nThe third stack is:\n");
    printStack(top_3);
}
