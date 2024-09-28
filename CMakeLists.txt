cmake_minimum_required(VERSION 3.28)
project(ATM_Machine)

set(CMAKE_CXX_STANDARD 20)

add_executable(ATM_Machine main.cpp
        Account.cpp
        Account.h
        UserInterface.cpp
        UserInterface.h)
