cmake_minimum_required(VERSION 3.20)
project(CMSC_257 C)

set(CMAKE_C_STANDARD 99)

#add_subdirectory(HW_5)
#add_subdirectory(Lab_3)
#add_subdirectory(Lab_4)
#add_subdirectory(Lab_5)
#add_subdirectory(Lab_6)
#add_subdirectory(Lab_7)
#add_subdirectory(Lab_8)
#add_subdirectory(Lab_9)
#add_subdirectory(Lab_10)
add_subdirectory(Assignment_1)
#add_subdirectory(Project_2)
#add_subdirectory(Project_3)
#add_subdirectory(Test_2)


# HW 5 Executable
#add_executable(${PROJECT_NAME} HW_5 HW_5/main.c)

# Lab 3 Executable
#add_executable(${PROJECT_NAME} Lab_3 Lab_3/lab3main.c. Lab_3/lab3header.h Lab_3/lab3support.c)

# Lab 4 Executable
#add_executable(${PROJECT_NAME} Lab_4 Lab_4/lab4.c)

# Lab 5 Executable
#add_executable(${PROJECT_NAME} Lab_5 Lab_5/integer-rep.c)

# Lab 6 Executable
#add_executable(${PROJECT_NAME} Lab_6 Lab_6/dynamic.c)

# Lab 7 Executable
#add_executable(${PROJECT_NAME} Lab_7 Lab_7/lab7.c)

# Lab 8 Executable
#add_executable(${PROJECT_NAME} Lab_8 Lab_8/sample.c)

# Lab 9 Executable
#add_executable(${PROJECT_NAME} Lab_9 Lab_9/lsh-master/src/main.c)

# Lab 10 Executable
#add_executable(${PROJECT_NAME} Lab_10 Lab_10/hellobug.c)

# Project 1 Executable
add_executable(${PROJECT_NAME} Assignment_1 Assignment_1/Analyzer.c Assignment_1/Analyzer.h Assignment_1/Givens.c Assignment_1/Givens.h Assignment_1/Parser.c Assignment_1/Parser.h Assignment_1/Tokenizer.c Assignment_1/Tokenizer.h)

# Project 2 Executable
#add_executable(${PROJECT_NAME} Project_2 Project_2/p2-support.c Project_2/p2-support.h Project_2/cmsc257-f21-p2.c)

# Project 3 Executable
#add_executable(${PROJECT_NAME} Project_3 Project_3/csapp.c Project_3/csapp.h Project_3/shellex.c)

# Test 2 Executable
#add_executable(${PROJECT_NAME} Test_2 Test_2/main.c Test_2/main.h Test_2/main.h)

# Main
#add_executable(Computer_System main.c)