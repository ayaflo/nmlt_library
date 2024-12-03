cmake_minimum_required(VERSION 3.29)
project(nmlt_library)

set(CMAKE_CXX_STANDARD 17)

add_executable(nmlt_library main.cpp
        Reader.h
        Book.h
        Transaction.h
        Reader.cpp
        Book.cpp
        Transaction.cpp
        Data.h
        Function.h
        Function.cpp
)
