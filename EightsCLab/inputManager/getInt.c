#include <stdio.h>
#include <stdlib.h>

#include "../memoryAllocation/memoryAllocation.h"


static void* inputStringFromKeyboard(char* ptr)
{
	char symbol = getchar();
	for (int i = 0, j = 5; symbol != '\n'; ++i)
	{
		ptr[i] = symbol;
		ptr[i + 1] = '\0';
		symbol = getchar();

		if (i >= j)
		{
			j += 5;
			ptr = safeRealloc(ptr, j * sizeof(char) - 1);
		}
	}

	return ptr;
}


static void* deleteEndAndBeginSpaces(char* ptr)
{
	if (ptr == NULL)
	{
		fprintf(stderr, "\nError: Pointer is NULL.\n");
		exit(EXIT_FAILURE);
	}

	int i = 0;
	for (; ptr[i] == ' '; ++i) {}

	int j = 0;
	for (; ptr[i] != '\0'; ++i, ++j)
	{
		ptr[j] = ptr[i];
	}

	for (--j ;ptr[j] == ' '; --j) {}

	ptr = safeRealloc(ptr, ++j * sizeof(char));

	ptr[j] = '\0';

	return ptr;
}


static int calculateSign(const char* ptr)
{
	if (ptr == NULL)
	{
		fprintf(stderr, "\nError: Pointer is NULL.\n");
		exit(EXIT_FAILURE);
	}

	if (ptr[0] == '-')
		return -1;

	return 1;
}


static void* deleteSign(char* ptr)
{
	if (ptr == NULL)
	{
		fprintf(stderr, "\nError: Pointer is NULL.\n");
		exit(EXIT_FAILURE);
	}

	if (ptr[0] == '-' || ptr[0] == '+')
	{
		int i = 1;
		for (; ptr[i] != '\0'; ++i)
		{
			ptr[i - 1] = ptr[i];
		}

		ptr = safeRealloc(ptr, --i * sizeof(char));
		ptr[i] = '\0';
	}

	return ptr;
}


static int isStringNumeric(const char* ptr)
{
	if (ptr == NULL)
	{
		fprintf(stderr, "\nError: Pointer is NULL.\n");
		exit(EXIT_FAILURE);
	}

	for (int i = 0; ptr[i] != '\0'; ++i)
	{
		if (ptr[i] > '9' || ptr[i] < '0')
		{
			puts("Invalid input! The value must be integer.");
			return 0;
		}
	}

	return 1;
}


static int convertStringToUnsignedInt(const char* ptr)
{
	if (ptr == NULL)
	{
		fprintf(stderr, "\nError: Pointer is NULL.\n");
		exit(EXIT_FAILURE);
	}

	int i = 0;
	for (; ptr[i] != '\0'; ++i) {}

	int number = 0; int digit = 1;
	for (--i; i >= 0; --i)
	{
		const long long summand = (long long)(ptr[i] - '0') * digit;
		if (summand > INT_MAX - number)
			return -1;

		number += (int)summand;
		digit *= 10;
	}

	return number;
}


static int isNumberOverflow(const char* ptr)
{
	if (ptr == NULL)
	{
		fprintf(stderr, "\nError: Pointer is NULL.\n");
		exit(EXIT_FAILURE);
	}

	if (convertStringToUnsignedInt(ptr) == -1)
	{
		puts("The entered value is too large or too small.");
		return 0;
	}

	return 1;
}


static int convertUnsignedIntToInt(const char* ptr, const int sign)
{
	return convertStringToUnsignedInt(ptr) * sign;
}


int inputInt()
{
	char* ptr = safeMalloc(5 * sizeof(char));

	while (1)
	{
		ptr = inputStringFromKeyboard(ptr);

		ptr = deleteEndAndBeginSpaces(ptr);

		const int sign = calculateSign(ptr);

		ptr = deleteSign(ptr);

		if (isStringNumeric(ptr))
		{
			if (isNumberOverflow(ptr))
			{
				const int number = convertUnsignedIntToInt(ptr, sign);
				free(ptr);
				return number;
			}
		}
	}
}


int inputIntInRange(const int min_value, const int max_value)
{
	while (1)
	{
		const int number = inputInt();

		if (number >= min_value && number <= max_value)
			return number;

		printf("The value must be between %d and %d.\n", min_value, max_value);
	}
}


int generateRandomIntInRange(const int min_value, const int max_value)
{
	return rand() % (max_value - min_value + 1) + min_value;
}