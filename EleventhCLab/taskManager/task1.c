/*1. Создать стек для целых чисел. Максимальный размер стека вводится с экрана. Найти сумму
четных элементов стека.*/

#include "../stackManager/stackManager.h"

#include <stdio.h>


void addEvenNumbers()
{
	Stack* top = NULL;

	top = fillStack(top);
	printf("Your stack is:\n");
	printStack(top);

	printf("\nThe sum of even numbers in stack is: %d\n", addEven(top));

	freeStack(top);
}