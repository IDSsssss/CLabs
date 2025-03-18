#include "studentsManager.h"
#include "../inputManager/getInt.h"
#include "../memoryManager/memoryManager.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../stringManager/stringManager.h"

#define DELIMITER "\n==================================================================\n"


static void inputEnrollmentDate(char date[9])
{
    puts("Enter year of enrollment.");
    const int year = inputIntInRange(0, 25);

    puts("Enter month of enrollment.");
    const int month = inputIntInRange(1, 12);

    puts("Enter day of enrollment.");
    const int day = inputIntInRange(1, 31);

    sprintf(date, "%2d.%2d.%2d", year, month, day);
}


Student initializeStudent(void)
{
    printf(DELIMITER);
    printf("\n");

    Student student;

    puts("Enter student record book number.");
    student.record_number = inputIntInRange(0, INT_MAX);

    puts("Enter student surname.");
    student.surname = enterWordFromConsole();

    puts("Enter student average point.");
    student.Info.average_point = inputIntInRange(0, 10);

    inputEnrollmentDate(student.Info.enrollment_date);

    printf(DELIMITER);
    return student;
}


void addStudentToArray(StudentsDescriptor* students)
{
    const Student student = initializeStudent();

    const int newCount = students -> length + 1;

    students -> students = safeRealloc(students -> students, newCount * sizeof(Student));

    students -> students[newCount - 1] = student;

    students -> length = newCount;
}


void printStudentsInfoAtIndex(const StudentsDescriptor* students, const int index)
{
    printf(DELIMITER);

    printf("Student`s record book number: %d\n", students -> students[index].record_number);

    printf("Student`s surname: %s\n", students -> students[index].surname);

    printf("Student`s enrollment date: %s\n", students -> students[index].Info.enrollment_date);

    printf("Student`s average point: %d", students -> students[index].Info.average_point);

    printf(DELIMITER);
}


static int findStudentsIndex(const StudentsDescriptor* students, const char* surname)
{
    int index = 0;

    while (index < students -> length && !compareStrings(students -> students[index].surname, surname))
    {
        ++index;
    }

    if (index == students -> length)
    {
        printf("\nThere are no students with surname '%s'", surname);
        return -1;
    }

    return index;
}


void printStudentInfoBySurname(const StudentsDescriptor* students)
{
    printf(DELIMITER);

    puts("Enter student`s surname.");
    char* surname = enterWordFromConsole();

    if (students -> length > 0)
    {
        const int index = findStudentsIndex(students, surname);

        if (index == -1)
        {
            free(surname);

            printf(DELIMITER);

            return;
        }
        printStudentsInfoAtIndex(students, index);
    }
    else
    {
        puts("\nThere are no students in list.");
    }

    free(surname);

    printf(DELIMITER);
}


void printStudentsInfo(const StudentsDescriptor* students)
{
    printf(DELIMITER);

    if (students -> length == 0)
    {
        printf("There are no students in list.");
    }
    else
    {
        for (int i = 0; i < students -> length; ++i)
        {
            printStudentsInfoAtIndex(students, i);
        }
    }

    printf(DELIMITER);
}


void deleteStudentAtIndex(StudentsDescriptor* students, const int index)
{
    free(students -> students[index].surname);

    --students -> length;

    if (students -> length > 0)
    {
        for (int i = index; i < students -> length; ++i)
            students -> students[i] = students -> students[i + 1];
    }

    students -> students = safeRealloc(students -> students, students -> length * sizeof(Student));
}


void deleteStudentBySurname(StudentsDescriptor* students)
{
    printf(DELIMITER);

    puts("Enter student`s surname.");
    char* surname = enterWordFromConsole();

    if (students -> length > 0)
    {
        const int index = findStudentsIndex(students, surname);

        if (index == -1)
        {
            free(surname);

            printf(DELIMITER);

            return;
        }

        deleteStudentAtIndex(students, index);
        printf("\n'%s' has been deleted.", surname);
    }
    else
    {
        puts("\nThere are no students in list.");
    }

    free(surname);

    printf(DELIMITER);
}


void deleteLazyStudents(StudentsDescriptor* students)
{
    printf(DELIMITER);

    puts("Enter minimum average point.");
    const int min_average_point = inputIntInRange(0, 10);

    for (int i = 0; i < students->length; ++i)
    {
        if (students->students[i].Info.average_point < min_average_point)
        {
            printf("\nStudent '%s' has been deleted.", students -> students[i].surname);
            deleteStudentAtIndex(students, i);

            --i;
        }
    }

    printf(DELIMITER);
}


void freeStudentsArray(StudentsDescriptor* students)
{
    for (int i = 0; i < students -> length; ++i)
    {
        free(students -> students[i].surname);
        students -> students[i].surname = NULL;
    }

    free(students -> students);
    students -> students = NULL;

    students -> length = 0;
}