cmake_minimum_required(VERSION 3.30)
project(TwelfthCLab C)

set(CMAKE_C_STANDARD 11)

add_executable(TwelfthCLab main.c
        taskManager/task1.c
        taskManager/task2.c
        taskManager/taskManager.c
        inputManager/getInt.c
        memoryManager/memoryManager.c
        taskManager/task3.c
        queueManager/queueManager.c
        queueManager/queueManager.h
        dequeManager/dequeManager.c
        dequeManager/dequeManager.h)
