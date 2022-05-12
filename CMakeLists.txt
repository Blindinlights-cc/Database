cmake_minimum_required(VERSION 3.23)
project(database)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(database
        database.cc
        database.hpp
        main.cpp
        statement.hpp)
