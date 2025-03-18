#ifndef STRING_MANAGER_H
#define STRING_MANAGER_H

#include <stdio.h>


char* allocateString(int length);

int calculateStringLength(const char* string);

int compareStrings(const char* first_string, const char* second_string);

char* enterLineFromConsole(void);

char* enterWordFromConsole(void);

char* readLineFromFile(FILE* file);

char* readWordFromFile(FILE* file);


#endif 