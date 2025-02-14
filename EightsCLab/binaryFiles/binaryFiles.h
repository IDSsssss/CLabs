#ifndef BINARYFILES_H
#define BINARYFILES_H

#include <stdio.h>


FILE* openFile(char* file_name, const char* mode);

char* enterFileName();

int calculateFileLength(FILE* file);

int getNumber(FILE* file, int index);

void insertNumber(FILE* file, int number, int index);

void swapNumbers(FILE* file, int first_index, int second_index);

void insertNumbersInDescendingOrder(FILE* file);

void fillFileRandomly(FILE* file);

void fillFileManually(FILE* file);

void printFile(FILE* file);


#endif