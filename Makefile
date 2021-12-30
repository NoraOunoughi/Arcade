##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

OBJ			=	$(SRC:.cpp=.o)

SRC			=	src/main.cpp		 		\
				src/Library/Library.cpp		\
				src/Core/Core.cpp			\
				src/Inputs/Inputs.cpp		\
				src/Exception/Exception.cpp	\

TEST_SRC	=

NAME		=	arcade

TEST_NAME	=	unit_tests

CC			=	g++

CFLAGS		=	-Wall -Wextra -ldl

CPPFLAGS	=	-I./lib/Display/ -I./src/Core/ -I./src/Library/ -I./src/Inputs/ -I./src/Assets/ -I./lib/Game/ -I./src/Exception/

TEST_CFLAGS	=	--coverage

TEST_LDFLAGS	=	-lcriterion -DUNIT_TEST

all:	sfml sdl pacman nibbler ncurse $(NAME)

$(NAME):	$(OBJ)
	@$(CC) $(OBJ) -o $(NAME) $(CFLAGS)
	@echo -e "Compile with $(SRC)files : $(GREEN)OK$(END)"
	@echo -e "Compile with $(CFLAGS) flags : $(GREEN)OK$(END)"
	@echo -e "$(GREEN)Project compile$(END)"

%.o : %.cpp
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<
	@echo -e "Compile $@ file : $(GREEN)OK$(END)"

debug: 	CPP_FLAGS += -g3 -ggdb
debug:	re

tests_run:
	@$(CC) $(TEST_SRC) -o $(TEST_NAME) $(TEST_LDFLAGS) $(TEST_CFLAGS) $(CPPFLAGS)
	@echo -e "Compile with $(SRC)files : $(GREEN)OK$(END)"
	@echo -e "Compile with $(LDFLAGS) $(CFLAGS) flags : $(GREEN)OK$(END)"
	@echo -e "$(GREEN)Unit tests compile$(END)"
	./$(TEST_NAME)

coverage:
	gcovr -b --exclude-directories tests
	gcovr -r . --exclude-directories tests

sfml:
	make -C lib/Display/SFML/

sdl:
	make -C lib/Display/SDL/

ncurse:
	make -C lib/Display/Ncurse/

pacman:
	make -C lib/Game/Pacman/

nibbler:
	make -C lib/Game/Nibbler/

core: $(NAME)

games: pacman nibbler

graphicals: sfml sdl


clean:
	@$(RM) $(OBJ) tests/*.o src/Assets/*.o
	@echo -e "Delete .o files : $(GREEN)OK$(END)"
	#@find -name "#*" -delete -o -name "*[#|~]" -delete
	@echo -e "Delete temporary files : $(GREEN)OK$(END)"
	#@find -name 'vgcore*' -delete
	@echo -e "Delete vgcore file : $(GREEN)OK$(END)"
	@make clean -C lib/Display/SFML
	@make clean -C lib/Game/Pacman
	@make clean -C lib/Display/SDL
	@make clean -C lib/Game/Nibbler
	@make clean -C lib/Display/Ncurse

fclean:	clean
	@$(RM) $(NAME) $(TEST_NAME) lib/arcade_sfml.so lib/arcade_pacman.so lib/Game/Nibbler.so lib/arcade_sdl2.so lib/arcade_nibbler.so lib/arcade_ncurses.so
	@echo -e "Delete binary file : $(GREEN)OK$(END)"
	#@find -name "*.gc*" -delete
	@echo -e "Delete gcda and gcno files : $(GREEN)OK$(END)"
	@make fclean -C lib/Display/SFML
	@make fclean -C lib/Game/Pacman
	@make fclean -C lib/Display/SDL
	@make fclean -C lib/Game/Nibbler
	@make fclean -C lib/Display/Ncurse

re:	fclean all

.PHONY:	all debug tests_run coverage sfml clean fclean re

END		=	\e[0m
RED		=	\e[0;31m
GREEN	=	\e[0;32m
BLEU	=	\e[0:34m
