/*Выполнить реверс элементов в файле.*/

#include "../binaryFiles/binaryFiles.h"
#include "../inputManager/getInt.h"
#include "../memoryAllocation/memoryAllocation.h"

#include <time.h>


void reverseFile(FILE* file)
{
	const int file_length = calculateFileLength(file);

	for (int i = 0, j = file_length - 1; i < j; ++i, --j)
	{
		swapNumbers(file, i, j);
	}
}


void task4()
{
	srand(time(NULL));

	char* file_name = enterFileName();
	printf("The name of your file is %s.\n\n", file_name);

	FILE* my_file = openFile(file_name, "w+b");

	fillFileRandomly(my_file);

	puts("The numbers in the file are:");
	printFile(my_file);

	reverseFile(my_file);

	puts("The numbers in the reversed file are:");
	printFile(my_file);

	fclose(my_file);
}