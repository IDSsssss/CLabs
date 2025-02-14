#include "../strings/strings.h"
#include "../memoryAllocation/memoryAllocation.h"
#include "../inputManager/getInt.h"

#include <stdio.h>
#include <stdlib.h>


FILE* openFile(char* file_name, const char* mode)
{
	FILE* file = fopen(file_name, mode);

	free(file_name);

	if (file == NULL)
	{
		fprintf(stderr, "\nFile opening failed\n");
		exit(EXIT_FAILURE);
	}

	return file;
}


void safeFread(void* buffer, const size_t elementSize, const size_t count, FILE* file)
{
	if(fread(buffer, elementSize, count, file) != count && feof(file) == 0)
	{
		fprintf(stderr, "\nFile reading failed!\n");
		exit(EXIT_FAILURE);
	}
}


void safeFwrite(const void* str, const size_t elementSize, const size_t count, FILE* file)
{
	if (fwrite(str, elementSize, count, file) != count)
	{
		fprintf(stderr, "\nFile writing failed!\n");
		exit(EXIT_FAILURE);
	}
}


void safeFseek(FILE* file, const long offset, const int origin)
{
	if (fseek(file, offset, origin) != 0)
	{
		fprintf(stderr, "\nFile writing failed!\n");
		exit(EXIT_FAILURE);
	}
}


long safeFtell(FILE* file)
{
	const long temp = ftell(file);
	if (temp == -1)
	{
		fprintf(stderr, "\nFile writing failed!\n");
		exit(EXIT_FAILURE);
	}
	return temp;
}


static char* addExtension(char* file_name)
{
	const int name_length = calculateStringSize(file_name);

	file_name = safeRealloc(file_name, sizeof(char) * (name_length + 5));

	const char* file_extension = ".bin";
	for (int i = name_length, j = 0; j < 5; ++i, ++j)
	{
		file_name[i] = file_extension[j];
	}

	return file_name;
}


char* enterFileName()
{
	puts("Enter file name.");

	char* file_name = inputString();

	file_name = addExtension(file_name);

	return file_name;
}


int calculateFileLength(FILE* file)
{
	safeFseek(file, 0, SEEK_END);

	const int file_length = safeFtell(file) / sizeof(int);

	safeFseek(file, 0, SEEK_SET);

	return file_length;
}


int getNumber(FILE* file, const int index)
{
	safeFseek(file, sizeof(int) * index, SEEK_SET);

	int number = 0;
	safeFread(&number, sizeof(int), 1, file);

	safeFseek(file, 0, SEEK_SET);

	return number;
}


void insertNumber(FILE* file, const int number, const int index)
{
	safeFseek(file, sizeof(int) * index, SEEK_SET);

	safeFwrite(&number, sizeof(int), 1, file);

	safeFseek(file, 0, SEEK_SET);
}


static void moveNumbers(FILE* file, const int first_index)
{
	const int file_length = calculateFileLength(file) - 1;

	for (int i = file_length; i >= first_index; --i)
	{
		insertNumber(file, getNumber(file, i), i + 1);
	}

	safeFseek(file, 0, SEEK_SET);
}


void swapNumbers(FILE* file, const int first_index, const int second_index)
{
	const int temp = getNumber(file, first_index);

	insertNumber(file, getNumber(file, second_index), first_index);

	insertNumber(file, temp, second_index);
}


static void insertNumberInDescendingOrder(FILE* file, const int number)
{
	const int file_length = calculateFileLength(file);

	for (int i = 0; i <= file_length; ++i)
	{
		if (number >= getNumber(file, i) || i == file_length)
		{
			moveNumbers(file, i);

			insertNumber(file, number, i);

			return;
		}
	}
}


void insertNumbersInDescendingOrder(FILE* file)
{
	puts("\nEnter count of numbers to insert in range from 1 to 100.");
	const int numbers_count = inputIntInRange(1, 100);

	for (int i = 1; i <= numbers_count; ++i)
	{
		printf("Enter %d number.\n", i);
		insertNumberInDescendingOrder(file, inputIntInRange(-100, 100));
	}
}


void fillFileRandomly(FILE* file)
{
	safeFseek(file, 0, SEEK_SET);

	const int file_length = generateRandomIntInRange(1, 100);

	int number = 0;
	for (int i = 0; i < file_length; ++i)
	{
		number = generateRandomIntInRange(-100, 100);

		safeFwrite(&number, sizeof(int), 1, file);
	}

	safeFseek(file, 0, SEEK_SET);
}


void fillFileManually(FILE* file)
{
	puts("Enter numbers count in range from 1 to 100.");
	const int numbers_count = inputIntInRange(1, 100);

	int number = 0;
	for (int i = 1; i <= numbers_count; ++i)
	{
		printf("Enter %d number.\n", i);
		number = inputIntInRange(-100, 100);

		safeFwrite(&number, sizeof(int), 1, file);
	}

	safeFseek(file, 0, SEEK_SET);
}


void printFile(FILE* file)
{
	safeFseek(file, 0, SEEK_SET);

	for (int i = 1; i <= calculateFileLength(file); ++i)
	{
		printf("    The %d number is: %d\n", i, getNumber(file, i - 1));
	}

	safeFseek(file, 0, SEEK_SET);
}