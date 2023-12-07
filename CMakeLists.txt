cmake_minimum_required(VERSION 3.10)
project(rtype)

#set cpp version
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#set requiered packages
#find_package(??? REQUIRED)

#set source files
set(SOURCES
    source/main.cpp
)

#set include directories
set(INCLUDE_DIRS
    includes
)

#set binary output directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

add_executable(rtype ${SOURCES})
target_include_directories(rtype PRIVATE ${INCLUDE_DIRS})
