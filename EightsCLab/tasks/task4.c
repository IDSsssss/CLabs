/*Выполнить реверс элементов в файле.*/

#include "../binaryFiles/binaryFiles.h"


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
	FILE* my_file = openFile("w+b");

	celectMethodOfFillingFile(my_file);

	puts("The numbers in your file are:");
	printFile(my_file);

	reverseFile(my_file);

	puts("The numbers in reversed file are:");
	printFile(my_file);

	fclose(my_file);
}