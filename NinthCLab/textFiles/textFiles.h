#ifndef TEXTFILES_H
#define TEXTFILES_H

#include <stdio.h>


typedef struct
{
	FILE* file;
	char* file_name;
	int file_length;
}FileDescriptor;

void safeFseek(FILE* file, long offset, int origin);

void safeFgets(void* buffer, int count, FILE* file);

int safeFgetc(FILE* file);

void safeFputs(const void* str, FILE* file);

void safeFputc(int symbol, FILE* file);

FileDescriptor* createFileDescriptorWithArgv(char* file_name, const char* mode);

FileDescriptor* createFileDescriptor(const char* mode);

FileDescriptor* celectMethodOfCreatingFileDescriptor(int argc, char** argv);

char getSymbol(FILE* file, int index);

void insertSymbol(FILE* file, char symbol, int index);

void moveSymbols(FileDescriptor* file_descriptor, int first_index);

void swapSymbols(FILE* file, int first_index, int second_index);

void deleteFileContents(const FileDescriptor* file_descriptor);

void extendFileRandomly(FileDescriptor* file_descriptor);

void fillFileRandomly(FileDescriptor* file_descriptor);

void extendFileManually(FileDescriptor* file_descriptor);

void fillFileManually(FileDescriptor* file_descriptor);

void celectMethodOfFillingFile(FileDescriptor* file_descriptor);

void printFile(const FileDescriptor* file_descriptor);

void closeFile(FileDescriptor* file_descriptor);


#endif
