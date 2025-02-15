#ifndef BINARYFILES_H
#define BINARYFILES_H

#include <stdio.h>


typedef struct
{
	FILE* file;
	int file_length;
}FileDescriptor;

void safeFseek(FILE* file, long offset, int origin);

void safeFread(void* buffer, size_t elementSize, size_t count, FILE* file);

void safeFwrite(const void* str, size_t elementSize, size_t count, FILE* file);

long safeFtell(FILE* file);

FILE* openFile(const char* mode);

FileDescriptor* createFileDescriptor(const char* mode);

int getNumber(FILE* file, int index);

void insertNumber(FILE* file, int number, int index);

void insertNumbersInDescendingOrder(FileDescriptor* file_descriptor);

void swapNumbers(FILE* file, int first_index, int second_index);

void fillFileRandomly(FileDescriptor* file_descriptor);

void fillFileManually(FileDescriptor* file_descriptor);

void celectMethodOfFillingFile(FileDescriptor* file_descriptor);

void printFile(const FileDescriptor* file_descriptor);

void closeFile(FileDescriptor* file_descriptor);


#endif