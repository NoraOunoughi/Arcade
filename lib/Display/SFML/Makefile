##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

OBJ		=	$(SRC:.cpp=.o)

TEST_OBJ	=	$(TEST_SRC:.c=.o)

SRC			=	SFML.cpp						\
				../../../src/Inputs/Inputs.cpp	\
				../../../src/Assets/Assets.cpp	\

TEST_SRC	=

NAME		=	arcade_sfml.so

TEST_NAME	=	unit_tests

CC			=	gcc

CFLAGS		=	-Wall -Wextra

CPPFLAGS	=	-I./../ -I./../../../src/Inputs/ -I./../../../src/Assets/

DEBUGFLAGS	=	-g3 -ggdb

TEST_CFLAGS	=	--coverage

TEST_LDFLAGS	=	-lcriterion -DUNIT_TEST

all:	re

re:
	@$(CC) $(SRC) -c -fPIC $(CFLAGS) $(CPPFLAGS)
	@$(CC) -shared -o $(NAME) *.o -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
	@echo -e "Compile with $(SRC) files : $(GREEN)OK$(END)"
	@echo -e "Compile with $(CFLAGS) flags : $(GREEN)OK$(END)"
	@echo -e "Shared library compile : $(GREEN)OK$(END)"
	@mv -f $(NAME) ../../

debug: fclean
	    @$(CC) $(SRC) -c -fPIC $(CFLAGS) $(CPPFLAGS) $(DEBUGFLAGS)
		@$(CC) -shared -o $(NAME) $(DEBUGFLAGS) *.o
		@echo -e "Compile with $(SRC) files : $(GREEN)OK$(END)"
		@echo -e "Compile with $(CFLAGS) $(DEBUGFLAGS) flags : $(GREEN)OK$(END)"
		@echo -e "Shared library compile : $(GREEN)OK$(END)"


tests_run:	$(OBJ) $(TEST_OBJ)
	@$(CC) $(OBJ) $(TEST_OBJ) -o $(TEST_NAME) $(TEST_LDFLAGS) $(TEST_CFLAGS) $(CPPFLAGS)
	@echo -e "Compile with $(SRC) files : $(GREEN)OK$(END)"
	@echo -e "Compile with $(LDFLAGS) $(CFLAGS) flags : $(GREEN)OK$(END)"
	@echo -e "Unit tests compile : $(GREEN)OK$(END)"
	./$(TEST_NAME)

coverage:
	gcovr -b --exclude-directories tests
	gcovr -r . --exclude-directories tests

clean:
	@$(RM) *.o
	@echo -e "Delete .o files : $(GREEN)OK$(END)"

fclean:	clean
	@$(RM) $(NAME) $(TEST_NAME)
	@echo -e "Delete binary file : $(GREEN)OK$(END)"

re:	fclean all

.PHONY:	all clean fclean re

END		=	\e[0m
RED		=	\e[0;31m
GREEN	=	\e[0;32m
BLEU	=	\e[0:34m
