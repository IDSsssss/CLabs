#include "../strings/strings.h"
#include "../memoryAllocation/memoryAllocation.h"
#include "../inputManager/getInt.h"
#include "binaryFiles.h"

#include <stdio.h>
#include <time.h>


void safeFseek(FILE* file, const long offset, const int origin)
{
	if (fseek(file, offset, origin) != 0)
	{
		fprintf(stderr, "\nFile writing failed!\n");
		exit(EXIT_FAILURE);
	}
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


static char* enterFileName()
{
	puts("Enter file name.");

	char* file_name = inputString();

	file_name = addExtension(file_name);

	return file_name;
}


static void goToBeginning(FILE* file)
{
	safeFseek(file, 0, SEEK_SET);
}


static void goToEnd(FILE* file)
{
	safeFseek(file, 0, SEEK_END);
}


static int calculateFileLength(FILE* file)
{
	goToEnd(file);

	const int file_length = safeFtell(file) / sizeof(int);

	return file_length;
}


FILE* openFile(const char* mode)
{
	char* file_name = enterFileName();
	printf("The name of your file is %s.\n\n", file_name);

	FILE* file = fopen(file_name, mode);

	free(file_name);

	if (file == NULL)
	{
		fprintf(stderr, "\nFile opening failed\n");
		exit(EXIT_FAILURE);
	}

	return file;
}


FileDescriptor* createFileDescriptor(const char* mode)
{
	FileDescriptor* file_descriptor = safeMalloc(sizeof(FILE*) + sizeof(int));

	file_descriptor->file = openFile(mode);

	file_descriptor->file_length = calculateFileLength(file_descriptor->file);

	return file_descriptor;
}


int getNumber(FILE* file, const int index)
{
	safeFseek(file, sizeof(int) * index, SEEK_SET);

	int number = 0;
	safeFread(&number, sizeof(int), 1, file);

	return number;
}


void insertNumber(FILE* file, const int number, const int index)
{
	safeFseek(file, sizeof(int) * index, SEEK_SET);

	safeFwrite(&number, sizeof(int), 1, file);
}


static void moveNumbers(const FileDescriptor* file_descriptor, const int first_index)
{
	for (int i = file_descriptor -> file_length - 1; i >= first_index; --i)
	{
		insertNumber(file_descriptor -> file, getNumber(file_descriptor -> file, i), i + 1);
	}
}


static void insertNumberInDescendingOrder(FileDescriptor* file_descriptor, const int number)
{
	for (int i = 0; i <= file_descriptor -> file_length; ++i)
	{
		if (number >= getNumber(file_descriptor -> file, i) || i == file_descriptor -> file_length)
		{
			moveNumbers(file_descriptor, i);

			insertNumber(file_descriptor -> file, number, i);

			++file_descriptor -> file_length;

			return;
		}
	}
}


void insertNumbersInDescendingOrder(FileDescriptor* file_descriptor)
{
	puts("\nEnter count of numbers to insert in range from 1 to 100.");
	const int numbers_count = inputIntInRange(1, 100);

	for (int i = 0; i < numbers_count; ++i)
	{
		printf("Enter %d number.\n", i + 1);
		insertNumberInDescendingOrder(file_descriptor, inputIntInRange(-100, 100));
	}
}


void swapNumbers(FILE* file, const int first_index, const int second_index)
{
	const int temp = getNumber(file, first_index);

	insertNumber(file, getNumber(file, second_index), first_index);

	insertNumber(file, temp, second_index);
}


void fillFileRandomly(FileDescriptor* file_descriptor)
{
	srand(time(NULL));

	file_descriptor -> file_length = generateRandomIntInRange(1, 100);

	for (int i = 0; i < file_descriptor -> file_length; ++i)
	{
		insertNumber(file_descriptor -> file, generateRandomIntInRange(-100, 100), i);
	}
}


void fillFileManually(FileDescriptor* file_descriptor)
{
	puts("Enter numbers count in range from 1 to 100.");
	file_descriptor -> file_length = inputIntInRange(1, 100);

	for (int i = 0; i < file_descriptor -> file_length; ++i)
	{
		printf("Enter %d number.\n", i + 1);
		insertNumber(file_descriptor -> file, inputIntInRange(-100, 100), i);
	}
}


void celectMethodOfFillingFile(FileDescriptor* file_descriptor)
{
	puts("Enter '1' to enter array elements from the keyboard, '2' to initialize it with random values.");
	switch (inputIntInRange(1, 2))
	{
		case 1:
			fillFileManually(file_descriptor);
		break;

		case 2:
			fillFileRandomly(file_descriptor);
		break;

		default:;
	}
}


void printFile(const FileDescriptor* file_descriptor)
{
	goToBeginning(file_descriptor -> file);

	for (int i = 0; i < file_descriptor -> file_length; ++i)
	{
		printf("    The %d number is: %d\n", i + 1, getNumber(file_descriptor -> file, i));
	}
}


void closeFile(FileDescriptor* file_descriptor)
{
	fclose(file_descriptor->file);
	free(file_descriptor);
}