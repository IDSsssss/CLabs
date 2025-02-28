#include "tasks/tasks.h"
#include "inputManager/getint.h"

#include <stdio.h>


void chooseTask(const int choice, FileDescriptor* file_descriptor)
{
    switch (choice)
    {
        case 1:
            task1(file_descriptor);
        break;

        case 2:
            task2(file_descriptor);
        break;

        case 3:
            task3(file_descriptor);
        break;

        case 4:
            task4(file_descriptor);
        break;

        default:;
    }
}


int main(const int argc, char** argv)
{
    FileDescriptor* file_descriptor = celectMethodOfCreatingFileDescriptor(argc, argv);

    while (1)
    {
        puts("\nEnter the task number (1-4) or 5 to exit.");

        const int choice = inputIntInRange(1, 5);

        if (choice != 5)
        {
            chooseTask(choice, file_descriptor);
        }
        else
        {
            closeFile(file_descriptor);
            return 0;
        }
    }
}