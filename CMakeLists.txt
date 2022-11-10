cmake_minimum_required(VERSION 3.0)

set(myproject "Proiect Paoo")

project(${myproject})

add_subdirectory(src)

add_executable(main main.cpp)