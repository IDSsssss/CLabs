#include "stringManager.h"
#include "../memoryManager/memoryManager.h"

#include <stdio.h>

#define START_BUFFER_SIZE 4


char* allocateString(const int length)
{
    return safeMalloc((length + 1) * sizeof(char));
}


int calculateStringLength(const char* string)
{
    int length = 0;

    while (string[length] != '\0')
    {
        length++;
    }

    return length;
}


int compareStrings(const char* first_string, const char* second_string)
{
    while (*first_string != '\0' || *second_string != '\0')
    {
        if (*first_string != *second_string)
        {
            return 0;
        }

        ++first_string;
        ++second_string;
    }

    return 1;
}


static char* manageBuffer(char* buffer, const int current_index, int* capacity)
{
    if (current_index == *capacity)
    {
        buffer = safeRealloc(buffer, *capacity += 4);
    }

    return buffer;
}


static char* readStringFromInputStream(FILE* stream, const int is_whole_line)
{
    char* buffer = allocateString(START_BUFFER_SIZE);

    int capacity = START_BUFFER_SIZE, current_index = 0, symbol = getc(stream);

    while ((is_whole_line && symbol != '\n' && symbol != EOF) || (!is_whole_line && symbol != ' ' && symbol != '\n' && symbol != EOF))
    {
        buffer[current_index] = (char)symbol;
        buffer = manageBuffer(buffer, ++current_index, &capacity);

        symbol = getc(stream);
    }
    buffer[current_index] = '\0';

    return buffer;
}


char* enterLineFromConsole(void)
{
    return readStringFromInputStream(stdin, 1);
}


char* enterWordFromConsole(void)
{
    return readStringFromInputStream(stdin, 0);
}


char* readLineFromFile(FILE* file)
{
    return readStringFromInputStream(file, 1);
}


char* readWordFromFile(FILE* file)
{
    return readStringFromInputStream(file, 0);
}