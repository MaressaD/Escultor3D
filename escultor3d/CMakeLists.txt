cmake_minimum_required(VERSION 3.5)

project(escultor3D LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(escultor3D main.cpp)

install(TARGETS escultor3D
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
