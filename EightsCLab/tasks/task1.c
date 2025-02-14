/*С клавиатуры заполнить файл целыми числами.*/

#include "../binaryFiles/binaryFiles.h"
#include "../inputManager/getInt.h"


void task1()
{
	char* file_name = enterFileName();
	printf("The name of your file is %s.\n\n", file_name);

	FILE* my_file = openFile(file_name, "w+b");

	fillFileManually(my_file);

	puts("The numbers in your file are:\n");
	printFile(my_file);

	fclose(my_file);
}