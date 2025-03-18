#ifndef FILESMANAGER_H
#define FILESMANAGER_H

#include "../studentsManager/studentsManager.h"

#include <stdio.h>

#define MAX_LINE_LENGTH 256
#define BUFFER_STRING_LENGTH 100


FILE* openFile(const char* file_path, const char* mode);

int readIntegerNumber(FILE* file);

void saveStudentsToFile(const char* file_path, const StudentsDescriptor* students_descriptor);

StudentsDescriptor loadDataFromFile(const char* file_path);


#endif
