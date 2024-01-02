##
## EPITECH PROJECT, 2023
## R-TYPE
## File description:
## Makefile
##

CPP = g++
CPPFLAGS = -std=c++14 -g -I../Includes
LDFLAGS = -lboost_program_options -pthread

SRCS = main.cpp ./Client.cpp ./TCP_Client/TCP.cpp ./UDP_Client/UDP.cpp
OBJS = $(SRCS:.cpp=.o)
TARGET = client

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CPP) $(CPPFLAGS) $(LDFLAGS) $^ -o $@

%.o: %.cpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

re: clean all