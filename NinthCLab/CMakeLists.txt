cmake_minimum_required(VERSION 3.29)
project(NinthCLab C)

set(CMAKE_C_STANDARD 11)

add_executable(NinthCLab main.c
        inputManager/getInt.c
        memoryAllocation/memoryAllocation.c
        strings/strings.c
        strings/strings.h
        tasks/task1.c
        tasks/task2.c
        tasks/task3.c
        tasks/task4.c
        tasks/tasks.h
        textFiles/textFiles.c
        textFiles/textFiles.h)
