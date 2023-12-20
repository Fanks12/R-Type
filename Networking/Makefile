##
## EPITECH PROJECT, 2023
## Networking
## File description:
## Makefile
##

CPP = g++
CPPFLAGS = -std=c++14 -g -I./Includes
LDFLAGS = -lboost_program_options -pthread

SRCS = ./Server/main.cpp ./Server/Handle_message.cpp ./Server/Data.cpp ./Server/Server.cpp ./Server/TCP/ServerTCP.cpp ./Server/UDP/ServerUDP.cpp
OBJS = $(SRCS:.cpp=.o)
TARGET = server

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CPP) $(CPPFLAGS) $(LDFLAGS) $^ -o $@

%.o: %.cpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
