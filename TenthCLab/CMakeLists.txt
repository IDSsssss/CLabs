cmake_minimum_required(VERSION 3.30)
project(TenthCLab C)

set(CMAKE_C_STANDARD 11)

add_executable(TenthCLab main.c
        taskManager/taskManager.c
        inputManager/getInt.c
        memoryManager/memoryManager.c
        taskManager/task1.c
        taskManager/task2.c
        filesManager/filesManager.c
        studentsManager/studentsManager.c
        stringManager/stringManager.c
)
