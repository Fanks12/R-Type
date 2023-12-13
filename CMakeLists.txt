#set source files
set(SOURCES
    source/main.cpp
    source/event.cpp
)

#set include directories
set(INCLUDE_DIRS
    includes
)

#set link directories
find_package(Threads REQUIRED)

#set binary output directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

execute_process(COMMAND npm install axios)

add_executable(rtype ${SOURCES})
target_include_directories(rtype PRIVATE ${INCLUDE_DIRS})

target_link_libraries(rtype PRIVATE Threads::Threads)