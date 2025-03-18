#include "filesManager.h"

#include "../studentsManager/studentsManager.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "../memoryManager/memoryManager.h"
#include "../stringManager/stringManager.h"


FILE* openFile(const char* file_path, const char* mode)
{
	FILE* file = fopen(file_path, mode);

	if (file == NULL)
	{
		printf("Error opening the file %s\n", file_path);
		exit(EXIT_FAILURE);
	}

	return file;
}

int readIntegerNumber(FILE* file)
{
	const char* buf = readLineFromFile(file);

	return (int)strtol(buf, NULL, 10);
}


void saveStudentsToFile(const char* file_path, const StudentsDescriptor* students_descriptor)
{
	Student* struct_array = students_descriptor -> students;
	const int students_count = students_descriptor -> length;

	FILE* file = openFile(file_path, "w");

	fprintf(file, "%d\n", students_count);

	for (int i = 0; i < students_count; i++)
	{
		fprintf(file, "%d\n", struct_array[i].record_number);
		fprintf(file, "%s\n", struct_array[i].surname);
		fprintf(file, "%s\n", struct_array[i].Info.enrollment_date);
		fprintf(file, "%d\n", struct_array[i].Info.average_point);
	}

	fclose(file);
}


static void readEnrollmentDateFromFile(FILE* file, char enrollment_date[9])
{
	char* buffer = readLineFromFile(file);

	for (int i = 0; i < 8; ++i)
	{
		enrollment_date[i] = buffer[i];
	}
	enrollment_date[8] = '\0';

	free(buffer);
}



StudentsDescriptor loadDataFromFile(const char* file_path)
{
	FILE* file = openFile(file_path, "r");
	const int length = readIntegerNumber(file);

	StudentsDescriptor students_descriptor;
	Student* students = safeMalloc(length * sizeof(Student));

	for (int i = 0; i < length; i++)
	{
		students[i].record_number = readIntegerNumber(file);

		students[i].surname = readLineFromFile(file);

		readEnrollmentDateFromFile(file, students[i].Info.enrollment_date);

		students[i].Info.average_point = readIntegerNumber(file);
	}
	fclose(file);

	students_descriptor.students = students;
	students_descriptor.length = length;

	return students_descriptor;
}