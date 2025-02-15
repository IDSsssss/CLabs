/*Числа образуют невозрастающую последовательность. Несколько
элементов, идущих подряд, могут быть равны между собой. Сколько
различных чисел имеется в файле?*/

#include "../binaryFiles/binaryFiles.h"
#include "../sorting/sorting.h"


int calculateUniqueNumbersCount(FILE* file)
{
	const int subsequence_length = calculateFileLength(file);

	int current_number = 0, previous_number = getNumber(file, 0), unique_numbers_count = 1;

	for (int i = 1; i < subsequence_length; ++i)
	{
		current_number = getNumber(file, i);

		if (current_number != previous_number)
		{
			++unique_numbers_count;
		}

		previous_number = current_number;
	}

	return unique_numbers_count;
}


void task2()
{
	FILE* my_file = openFile("w+b");

	celectMethodOfFillingFile(my_file);

	sortFile(my_file);

	puts("Numbers of subsequence in your file are:");
	printFile(my_file);

	printf("\nThere are %d unique numbers in your subsequence.\n", calculateUniqueNumbersCount(my_file));

	fclose(my_file);
}