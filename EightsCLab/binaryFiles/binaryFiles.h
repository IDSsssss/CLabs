#ifndef BINARYFILES_H
#define BINARYFILES_H

#include <stdio.h>


FILE* openFile(const char* mode);

void safeFseek(FILE* file, long offset, int origin);

void safeFread(void* buffer, size_t elementSize, size_t count, FILE* file);

void safeFwrite(const void* str, size_t elementSize, size_t count, FILE* file);

long safeFtell(FILE* file);

int calculateFileLength(FILE* file);

int getNumber(FILE* file, int index);

void insertNumber(FILE* file, int number, int index);

void insertNumbersInDescendingOrder(FILE* file);

void swapNumbers(FILE* file, int first_index, int second_index);

void fillFileRandomly(FILE* file);

void fillFileManually(FILE* file);

void celectMethodOfFillingFile(FILE* file);

void printFile(FILE* file);


#endif