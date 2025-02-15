/*Числа образуют невозрастающую последовательность. Несколько
элементов, идущих подряд, могут быть равны между собой. Сколько
различных чисел имеется в файле?*/

#include "../binaryFiles/binaryFiles.h"
#include "../sorting/sorting.h"


int calculateUniqueNumbersCount(const FileDescriptor* file_descriptor)
{
	int current_number = 0, previous_number = getNumber(file_descriptor -> file, 0), unique_numbers_count = 1;

	for (int i = 1; i < file_descriptor -> file_length; ++i)
	{
		current_number = getNumber(file_descriptor -> file, i);

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
	FileDescriptor* file_descriptor = createFileDescriptor("w+b");

	celectMethodOfFillingFile(file_descriptor);

	sortFile(file_descriptor);

	puts("Numbers of subsequence in your file are:");
	printFile(file_descriptor);

	printf("\nThere are %d unique numbers in your subsequence.\n", calculateUniqueNumbersCount(file_descriptor));

	closeFile(file_descriptor);
}