/*1. Найти и вывести целое число в 4 раза меньше заданного, не выполняя
деления и не используя операцию взятия остатка от деления.*/

#include "../inputManager/getInt.h"

#include <stdio.h>


union Number
{
	int num;
	struct
	{
		unsigned lower_two_bits : 2;
		unsigned rest_of_bits : 30;
	}Bits;
};


void executeTask1()
{
	union Number number;

	puts("\nEnter value in range from 0 to INT_MAX");
	number.num = inputIntInRange(0, INT_MAX);

	printf("\nThe result of dividing %d by four is %d.\n", number.num, number.Bits.rest_of_bits);
}