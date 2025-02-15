/*С клавиатуры заполнить файл целыми числами.*/

#include "../binaryFiles/binaryFiles.h"


void task1()
{
	FILE* my_file = openFile("w+b");

	fillFileManually(my_file);

	puts("The numbers in your file are:\n");
	printFile(my_file);

	fclose(my_file);
}