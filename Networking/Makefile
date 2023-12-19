CPP = g++
CPPFLAGS = -std=c++14 -g
LDFLAGS = -lboost_program_options -pthread

SRCS = main.cpp Handle_message.cpp Server.cpp ServerTCP.cpp ServerUDP.cpp
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
