cmake_minimum_required(VERSION 3.10)
project(rtype)

#set cpp version
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#set requiered packages
#find_package(??? REQUIRED)

#set source files
set(SOURCES
    source/rtype.cpp
)

#set include directories
set(INCLUDE_DIRS
    ecs/includes
    ecs/includes/system
    ecs/includes/components
    ecs/includes/event
    includes
)

#set link directories

#set binary output directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

# #install dependencies
# execute_process(COMMAND sudo dnf install SFML)
# execute_process(COMMAND sudo dnf install asio-devel.x86_64)

find_package(Threads REQUIRED)
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

add_executable(rtype ${SOURCES})
target_include_directories(rtype PRIVATE ${INCLUDE_DIRS})

target_link_libraries(rtype PRIVATE Threads::Threads)
target_link_libraries(rtype PRIVATE sfml-graphics sfml-window sfml-system)
