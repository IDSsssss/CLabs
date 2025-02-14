cmake_minimum_required(VERSION 3.29)
project(EightsCLab C)

set(CMAKE_C_STANDARD 11)

add_executable(EightsCLab main.c
        tasks/task4.c
        tasks/task3.c
        tasks/task2.c
        tasks/task1.c
        inputManager/getInt.c
        memoryAllocation/memoryAllocation.c
        binaryFiles/binaryFiles.h
        binaryFiles/binaryFiles.c
        strings/strings.c
        strings/strings.h
        sorting/sorting.c)
