#include "../memoryAllocation/memoryAllocation.h"

#include <stdio.h>


char* inputString()
{
	int j = 10;
	char* string = safeMalloc(j * sizeof(char));

	while (1)
	{
		char symbol = getchar();

		if (symbol != '\n')
		{
			for (int i = 0; symbol != '\n'; ++i)
			{
				string[i] = symbol;
				string[i + 1] = '\0';
				symbol = getchar();

				if (i + 1 >= j)
				{
					j += 10;
					string = safeRealloc(string, j * sizeof(char));
				}
			}

			return string;
		}

		puts("You have not entered a string. Please re-enter.");
	}
}


char inputSymbol()
{
	puts("Enter symbol");
	while (1)
	{
		const char symbol = getchar();

		if (symbol != '\n' && getchar() == '\n')
			return symbol;

		puts("Invalid input! Please re-enter.");

		while (getchar() != '\n'){}
	}
}


int calculateStringSize(const char* string)
{
	int size = 0;
	while (string[size] != '\0')
		++size;

	return size;
}