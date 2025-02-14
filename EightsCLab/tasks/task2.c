/*Числа образуют невозрастающую последовательность. Несколько
элементов, идущих подряд, могут быть равны между собой. Сколько
различных чисел имеется в файле?*/

#include "../binaryFiles/binaryFiles.h"
#include "../sorting/sorting.h"

#include <time.h>
#include <stdlib.h>


int calculateUniqueNumbersCount(FILE* file)
{
	const int subsequence_length = calculateFileLength(file);
	fseek(file, 0, SEEK_SET);

	int current_number = 0, previous_number = 0, unique_numbers_count = 1;

	fread(&previous_number, sizeof(int), 1, file);

	for (int i = 1; i <= subsequence_length; ++i)
	{
		fread(&current_number, sizeof(int), 1, file);

		if (current_number != previous_number)
		{
			++unique_numbers_count;
		}

		previous_number = current_number;
	}

	fseek(file, 0, SEEK_SET);

	return unique_numbers_count;
}


void task2()
{
	srand(time(NULL));

	char* file_name = enterFileName();
	printf("The name of your file is %s.\n\n", file_name);

	FILE* my_file = openFile(file_name, "w+b");

	fillFileRandomly(my_file);

	sortFile(my_file);

	puts("Numbers of your subsequence are:");
	printFile(my_file);

	printf("\nThere are %d unique numbers in your subsequence.\n", calculateUniqueNumbersCount(my_file));

	fclose(my_file);
}