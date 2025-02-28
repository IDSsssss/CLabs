#include "../strings/strings.h"
#include "../memoryAllocation/memoryAllocation.h"
#include "../inputManager/getInt.h"
#include "textFiles.h"

#include <time.h>


void safeFseek(FILE* file, const long offset, const int origin)
{
	if (fseek(file, offset, origin) != 0)
	{
		fprintf(stderr, "\nFile writing failed4!\n");
		exit(EXIT_FAILURE);
	}
}


void safeFgets(void* buffer, const int count, FILE* file)
{
	if(fgets(buffer, count, file) == NULL)
	{
		fprintf(stderr, "\nFile reading failed!\n");
		exit(EXIT_FAILURE);
	}
}


int safeFgetc(FILE* file)
{
	const char symbol = fgetc(file);

	if (symbol == EOF && feof(file) == 0)
	{
		fprintf(stderr, "\nFile reading failed!\n");
		exit(EXIT_FAILURE);
	}

	return symbol;
}


void safeFputs(const void* str, FILE* file)
{
	if (fputs(str, file) == EOF)
	{
		fprintf(stderr, "\nFile writing failed3!\n");
		exit(EXIT_FAILURE);
	}
}


void safeFputc(const int symbol, FILE* file)
{
	if (fputc(symbol, file) == EOF)
	{
		fprintf(stderr, "\nFile writing failed2!\n");
		exit(EXIT_FAILURE);
	}
}


static long safeFtell(FILE* file)
{
	const long temp = ftell(file);
	if (temp == -1)
	{
		fprintf(stderr, "\nFile writing failed1!\n");
		exit(EXIT_FAILURE);
	}

	return temp;
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

	const int file_length = safeFtell(file) / sizeof(char);

	return file_length;
}


static char* addExtension(char* file_name)
{
	const int name_length = calculateStringSize(file_name);

	file_name = safeRealloc(file_name, sizeof(char) * (name_length + 5));

	const char* file_extension = ".txt";
	for (int i = name_length, j = 0; j < 5; ++i, ++j)
	{
		file_name[i] = file_extension[j];
	}

	return file_name;
}


static char* enterFileName()
{
	puts("\nEnter file name.");
	char* file_name = inputString();

	file_name = addExtension(file_name);

	return file_name;
}


static FILE* openFile(const char* file_name, const char* mode)
{
	FILE* file = fopen(file_name, mode);
	if (file == NULL)
	{
		fprintf(stderr, "\nFile opening failed0!\n");
		exit(EXIT_FAILURE);
	}

	return file;
}


FileDescriptor* createFileDescriptorWithArgv(char* file_name, const char* mode)
{
	file_name = addExtension(file_name);
	printf("The name of your file is %s.\n\n", file_name);

	FileDescriptor* file_descriptor = safeMalloc(sizeof(file_descriptor));

	file_descriptor -> file_name = file_name;

	file_descriptor -> file = openFile(file_name, mode);

	file_descriptor -> file_length = calculateFileLength(file_descriptor -> file);

	return file_descriptor;
}


FileDescriptor* createFileDescriptor(const char* mode)
{
	char* file_name = enterFileName();
	printf("The name of your file is %s.\n\n", file_name);

	FileDescriptor* file_descriptor = safeMalloc(sizeof(file_descriptor));

	file_descriptor -> file_name = file_name;

	file_descriptor -> file = openFile(file_name, mode);

	file_descriptor -> file_length = calculateFileLength(file_descriptor -> file);

	return file_descriptor;
}


FileDescriptor* celectMethodOfCreatingFileDescriptor(const int argc, char** argv)
{
	if (argc >= 2)
	{
		return createFileDescriptorWithArgv(argv[1], "a+");
	}

	return createFileDescriptor("a+");
}


char getSymbol(FILE* file, const int index)
{
	safeFseek(file, sizeof(char) * index, SEEK_SET);

	return safeFgetc(file);
}


void insertSymbol(FILE* file, const char symbol, const int index)
{
	safeFseek(file, sizeof(char) * index, SEEK_SET);

	safeFputc(symbol, file);
}


void moveSymbols(FileDescriptor* file_descriptor, const int first_index)
{
	for (int i = file_descriptor -> file_length - 1; i >= first_index; --i)
	{
		insertSymbol(file_descriptor -> file, getSymbol(file_descriptor -> file, i), i + 1);
	}

	++file_descriptor -> file_length;
}


void swapSymbols(FILE* file, const int first_index, const int second_index)
{
	const char temp = getSymbol(file, first_index);

	insertSymbol(file, getSymbol(file, second_index), first_index);

	insertSymbol(file, temp, second_index);
}


void deleteFileContents(const FileDescriptor* file_descriptor)
{
	fclose(file_descriptor -> file);
	openFile(file_descriptor -> file_name, "w");

	fclose(file_descriptor -> file);
	openFile(file_descriptor -> file_name, "a+");
}


void extendFileRandomly(FileDescriptor* file_descriptor)
{
	srand(time(NULL));

	goToEnd(file_descriptor -> file);

	file_descriptor -> file_length += generateRandomIntInRange(1, 100);

	for (int i = calculateFileLength(file_descriptor -> file) - 1; i < file_descriptor -> file_length; ++i)
	{
		insertSymbol(file_descriptor -> file, generateRandomIntInRange(32, 126), i);
	}
}


void fillFileRandomly(FileDescriptor* file_descriptor)
{
	deleteFileContents(file_descriptor);

	srand(time(NULL));

	file_descriptor -> file_length = generateRandomIntInRange(1, 100);

	for (int i = 0; i < file_descriptor -> file_length; ++i)
	{
		insertSymbol(file_descriptor -> file, generateRandomIntInRange(32, 126), i);
	}
}


void extendFileManually(FileDescriptor* file_descriptor)
{
	goToEnd(file_descriptor -> file);

	puts("Enter your string.");
	safeFputs(inputString(), file_descriptor -> file);

	file_descriptor -> file_length = calculateFileLength(file_descriptor -> file);
}


void fillFileManually(FileDescriptor* file_descriptor)
{

	deleteFileContents(file_descriptor);

	puts("Enter your string.");
	safeFputs(inputString(), file_descriptor -> file);

	file_descriptor -> file_length = calculateFileLength(file_descriptor -> file);
}


void celectMethodOfFillingFile(FileDescriptor* file_descriptor)
{
	puts("Enter '1' to fill file from the keyboard, '2' to fill it with random values,\n'3' to extend it from the keyboard, '4' to extend it with random values.");
	switch (inputIntInRange(1, 4))
	{
		case 1:
			fillFileManually(file_descriptor);
		break;

		case 2:
			fillFileRandomly(file_descriptor);
		break;

		case 3:
			extendFileManually(file_descriptor);
		break;

		case 4:
			extendFileRandomly(file_descriptor);
		break;

		default:;
	}
}


void printFile(const FileDescriptor* file_descriptor)
{
	goToBeginning(file_descriptor -> file);

	if(file_descriptor -> file_length == 0)
	{
		puts("     File is empty.\n");
		return;
	}

	printf("     ");
	for (int i = 0; i < file_descriptor -> file_length; ++i)
	{
		printf("%c", getSymbol(file_descriptor -> file, i));
	}
	puts("\n");
}


void closeFile(FileDescriptor* file_descriptor)
{
	fclose(file_descriptor -> file);
	free(file_descriptor);
}