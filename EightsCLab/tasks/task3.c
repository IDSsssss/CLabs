/*Дополнить файл числами в порядке невозрастания (числа вводятся в любом
порядке, программа записывает каждое число на то место, где оно должно
быть).*/

#include "../binaryFiles/binaryFiles.h"
#include "../inputManager/getInt.h"
#include "../memoryAllocation/memoryAllocation.h"
#include "../sorting/sorting.h"


void task3()
{
	char* file_name = enterFileName();
	printf("The name of your file is %s.\n\n", file_name);

	FILE* my_file = openFile(file_name, "r+b");

	puts("The numbers in the file are:");
	printFile(my_file);

	sortFile(my_file);

	insertNumbersInDescendingOrder(my_file);

	puts("The numbers in supplemented file are:");
	printFile(my_file);

	fclose(my_file);
}