cmake_minimum_required(VERSION 3.20.5)
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

#set binary output directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

add_executable(r-type_client
source/rtype.cpp
Networking/Client/TCP_Client/TCP.cpp
Networking/Client/UDP_Client/UDP.cpp
Networking/Client/Client.cpp
)
target_include_directories(r-type_client PRIVATE
ecs/includes
ecs/includes/system
ecs/includes/components
ecs/includes/event
includes
Networking/Includes
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

target_link_libraries(r-type_client PRIVATE Threads::Threads sfml-graphics sfml-audio sfml-window sfml-system)
target_link_libraries(r-type_server PRIVATE Threads::Threads)