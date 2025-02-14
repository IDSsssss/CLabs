#include <stdio.h>
#include <stdlib.h>


void* safeMalloc(const size_t size)
{
	void* ptr = malloc(size);

	if (ptr == NULL)
	{
		fprintf(stderr, "\nError: Failed to allocate memory!\n");
		exit(EXIT_FAILURE);
	}

	return ptr;
}


void* safeCalloc(const size_t num_of_elements, const size_t size)
{
	void* ptr = calloc(num_of_elements, size);

	if (ptr == NULL)
	{
		fprintf(stderr, "\nError: Failed to allocate memory!\n");
		exit(EXIT_FAILURE);
	}

	return ptr;
}


void* safeRealloc(void* currentPtr, const size_t newSize)
{
	void* newPtr = realloc(currentPtr, newSize);

	if (!newPtr && newSize != 0)
	{
		fprintf(stderr, "\nError: Failed to reallocate memory!\n");
		free(currentPtr);
		exit(EXIT_FAILURE);
	}

	return newPtr;
}