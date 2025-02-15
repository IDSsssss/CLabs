/*Выполнить реверс элементов в файле.*/

#include "../binaryFiles/binaryFiles.h"


void reverseFile(const FileDescriptor* file_descriptor)
{
	for (int i = 0, j = file_descriptor -> file_length - 1; i < j; ++i, --j)
	{
		swapNumbers(file_descriptor -> file, i, j);
	}
}


void task4()
{
	FileDescriptor* file_descriptor = createFileDescriptor("w+b");

	celectMethodOfFillingFile(file_descriptor);

	puts("The numbers in your file are:");
	printFile(file_descriptor);

	reverseFile(file_descriptor);

	puts("The numbers in reversed file are:");
	printFile(file_descriptor);

	closeFile(file_descriptor);
}