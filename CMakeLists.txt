cmake_minimum_required(VERSION 3.10)
project(r-type_client)
project(r-type_server)

#set cpp version
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#set requiered packages
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)
find_package(Threads REQUIRED)
find_package(Boost REQUIRED COMPONENTS program_options)

#set binary output directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

add_executable(r-type_client
ecs/main.cpp
)
target_include_directories(r-type_client PRIVATE
ecs/includes
ecs/includes/system
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
