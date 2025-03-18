#ifndef STUDENTSMANAGER_H
#define STUDENTSMANAGER_H


typedef struct
{
	int record_number;
	char* surname;
	struct
	{
		char enrollment_date[9];
		int average_point;
	}Info;
}Student;

typedef struct
{
	Student* students;
	int length;
} StudentsDescriptor;

Student initializeStudent(void);

void addStudentToArray(StudentsDescriptor* students);

void printStudentsInfoAtIndex(const StudentsDescriptor* students, int index);

void printStudentInfoBySurname(const StudentsDescriptor* students);

void printStudentsInfo(const StudentsDescriptor* students);

void deleteStudentAtIndex(StudentsDescriptor* students, int index);

void deleteStudentBySurname(StudentsDescriptor* students);

void deleteLazyStudents(StudentsDescriptor* students);

void freeStudentsArray(StudentsDescriptor* students);


#endif
