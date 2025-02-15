/*Дополнить файл числами в порядке невозрастания (числа вводятся в любом
порядке, программа записывает каждое число на то место, где оно должно
быть).*/

#include "../binaryFiles/binaryFiles.h"
#include "../sorting/sorting.h"


void task3()
{
	FileDescriptor* file_descriptor = createFileDescriptor("r+b");

	puts("The numbers in your file are:");
	printFile(file_descriptor);

	sortFile(file_descriptor);

	insertNumbersInDescendingOrder(file_descriptor);

	puts("The numbers in supplemented file are:");
	printFile(file_descriptor);

	closeFile(file_descriptor);
}