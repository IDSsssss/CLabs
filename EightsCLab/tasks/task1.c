/*С клавиатуры заполнить файл целыми числами.*/

#include "../binaryFiles/binaryFiles.h"


void task1()
{
	FileDescriptor* file_descriptor = createFileDescriptor("w+b");

	fillFileManually(file_descriptor);

	puts("The numbers in your file are:\n");
	printFile(file_descriptor);

	closeFile(file_descriptor);
}