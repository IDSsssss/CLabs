/*Дополнить файл числами в порядке невозрастания (числа вводятся в любом
порядке, программа записывает каждое число на то место, где оно должно
быть).*/

#include "../binaryFiles/binaryFiles.h"
#include "../sorting/sorting.h"


void task3()
{
	FILE* my_file = openFile("r+b");

	puts("The numbers in your file are:");
	printFile(my_file);

	sortFile(my_file);

	insertNumbersInDescendingOrder(my_file);

	puts("The numbers in supplemented file are:");
	printFile(my_file);

	fclose(my_file);
}