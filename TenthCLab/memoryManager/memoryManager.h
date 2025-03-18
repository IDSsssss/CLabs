#ifndef MEMORYMANAGER_H
#define MEMORYMANAGER_H

#include <stdlib.h>


void* safeMalloc(size_t size);

void* safeCalloc(size_t num_of_elements, size_t size);

void* safeRealloc(void* current_ptr, size_t new_size);

void copyMemory(void* dest, const void* src, size_t n);


#endif