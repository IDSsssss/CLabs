#ifndef MEMORYALLOCATION_H
#define MEMORYALLOCATION_H

#include <stdlib.h>


void* safeMalloc(size_t size);

void* safeCalloc(size_t num_of_elements, size_t size);

void* safeRealloc(void* current_ptr, size_t new_size);


#endif