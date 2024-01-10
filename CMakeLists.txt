cmake_minimum_required(VERSION 3.22)
project(r-type_client)
project(r-type_server)

#set cpp version
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#find libs
find_package(Threads REQUIRED)

# fetch content
include(FetchContent)
FetchContent_Declare(
    SFML
    GIT_REPOSITORY https://github.com/SFML/SFML
    GIT_TAG        2.5.1
)
FetchContent_MakeAvailable(SFML)

FetchContent_Declare(
    Boost
    GIT_REPOSITORY https://github.com/boostorg/boost
    GIT_TAG        boost-1.72.0
)
FetchContent_MakeAvailable(Boost)

#set binary output directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

add_executable(r-type_client
source/main.cpp
)
target_include_directories(r-type_client PRIVATE
ecs/includes
ecs/includes/system
ecs/includes/components
ecs/includes/event
)

add_executable(r-type_server
Networking/Server/main.cpp
Networking/Server/Handle_message.cpp
Networking/Server/Data.cpp
Networking/Server/Server.cpp
Networking/Server/TCP/ServerTCP.cpp
Networking/Server/UDP/ServerUDP.cpp
)
target_include_directories(r-type_server PRIVATE
Networking/Includes
)

target_link_libraries(r-type_client PRIVATE sfml-graphics sfml-window sfml-system)
target_link_libraries(r-type_server PRIVATE Threads::Threads)
target_link_libraries(r-type_server PRIVATE -lboost_program_options)