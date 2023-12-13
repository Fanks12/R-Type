##
## Makefile
## File description:
## rtype
##

SRC	=	source/main.cpp \

NAME	=	bootstrap

OBJ	=	$(SRC:.cpp=.o)

CPPFLAGS	=	-I./includes/ -I./ecs/includes/ -I./ecs/includes/system/ \
				-lsfml-graphics -lsfml-system -lsfml-window

CXXFLAGS = -Wall -Wextra

TESTS =

TEST_OBJ = $(TESTS:.cpp=.o)

LIB_TEST = libutest.a

TEST_NAME = unit_tests

TEST_INCLUDE = -lcriterion --coverage

all: $(NAME)

$(NAME):	$(OBJ)
		g++ -o $(NAME) $(SRC) $(CPPFLAGS) $(CXXFLAGS)

debug:	CXXFLAGS += -g3
debug:	$(OBJ)
	g++ -o $(NAME) $(OBJ) -L -lmy

unit_tests: fclean
		$(CC) $(TESTS) $(TEST_INCLUDE) -o $(TEST_NAME)

tests_run: unit_tests
			./$(TEST_NAME)
			gcovr

clean:
	rm -f ecs/includes/*~
	rm -f source/*.o
	rm -f source/*~
	rm -f includes/*~
	rm -f tests/*.o

fclean:	clean
	rm -f $(NAME)
	rm -f $(TEST_NAME)

re:	fclean all

help:
	@printf "LIST OF OPTIONS:\n\n"
	@printf "\thelp: displays all the make options and they're utilities\n\n"
	@printf "\tbuild: build the project\n\n"
	@printf "\tdebug: build the project with -g3 flag for valgrind\n\n"
	@printf "\tunit_tests: build units tests for the project\n\n"
	@printf "\ttests_run: build and execute unit tests for the project\n\n"
	@printf "\tclean: remove temporary files used for build\n\n"
	@printf "\tfclean: clean and remove binaries\n\n"
	@printf "\tre: fclean then build\n\n"

.PHONY:	all build debug clean fclean re
