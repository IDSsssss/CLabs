cmake_minimum_required(VERSION 3.30)
project(EleventhCLab C)

set(CMAKE_C_STANDARD 11)

add_executable(EleventhCLab main.c
        taskManager/task1.c
        taskManager/task2.c
        taskManager/taskManager.c
        inputManager/getInt.c
        memoryManager/memoryManager.c
        stackManager/stackManager.c)
