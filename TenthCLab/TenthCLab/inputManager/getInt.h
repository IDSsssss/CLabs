#ifndef GETINT_H
#define GETINT_H

#define INT_MAX 2147483647


int inputInt();

int calculateSign(const char* ptr);

void* deleteSign(char* ptr);

int convertStringToUnsignedInt(const char* ptr);

int inputIntInRange(int min_value, int max_value);

int generateRandomIntInRange(int min_value, int max_value);


#endif