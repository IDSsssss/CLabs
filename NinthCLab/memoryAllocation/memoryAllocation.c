#include "memoryAllocation.h"

#include <stdio.h>


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


void* safeRealloc(void* current_ptr, const size_t new_size)
{
	void* new_ptr = realloc(current_ptr, new_size);

	if (!new_ptr && new_size != 0)
	{
		fprintf(stderr, "\nError: Failed to reallocate memory!\n");
		free(current_ptr);
		exit(EXIT_FAILURE);
	}

	return new_ptr;
}