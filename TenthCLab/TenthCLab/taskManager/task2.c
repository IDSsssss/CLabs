/*2. Структура содержит информацию о студентах: номер зачётки (число),
фамилию (указатель), вложенную структуру – дату зачисления (строка
фиксированной длины) и средний балл. Найти студентов с заданной
фамилией. Удалить студентов с номером зачетки меньше заданного.*/

#include "../inputManager/getInt.h"
#include "../studentsManager/studentsManager.h"
#include "../filesManager/filesManager.h"

#include <stdio.h>


void chooseOption(const int choice, const char* file_path, StudentsDescriptor* students)
{
    switch (choice)
    {
        case 1:
            printStudentsInfo(students);
        break;

        case 2:
            addStudentToArray(students);
        break;

        case 3:
            deleteStudentBySurname(students);
        break;

        case 4:
            deleteLazyStudents(students);
        break;

        case 5:
            printStudentInfoBySurname(students);
        break;

        case 6:
            saveStudentsToFile(file_path, students);
            freeStudentsArray(students);
        break;

        default:;
    }
}


void executeTask2(const char* file_path)
{
    StudentsDescriptor students_descriptor;

    students_descriptor = loadDataFromFile(file_path);

    while (1)
    {
        printf("\n1 -- show students.\n2 -- add student.\n3 - delete student.\n4 -- delete lazy students.\n5 -- show student info.\n6 -- exit.\n");
        const int choice = inputIntInRange(1, 6);

        chooseOption(choice, file_path, &students_descriptor);

        if (choice == 6)
        {
            return;
        }
    }
}