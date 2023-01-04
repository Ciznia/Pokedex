##
## EPITECH PROJECT, 2022
## MAKEFILE
## File description:
## MAKEFILE FILE
##

SRC		=	./src/search_bar.c	\
			./src/main.c		\
			./src/my_strcmp.c

TEST 	=	./test/

NAME	=	search-bar

BIN		= 	unit_tests

OBJ		=	$(SRC:.c=.o)

CFLAGS	= 	-Wall -Wextra -I ./include
GFLAGS	=	-lcsfml-system -lcsfml-graphics -lcsfml-audio -lcsfml-window

UNITFL	=	-lcriterion --coverage

DEBUGFL	=	-g 	-ggdb3

all:		$(OBJ)
			gcc -o $(NAME) $(OBJ) $(CFLAGS) $(GFLAGS)

clean:
			rm -f $(OBJ)
			rm -f *.gcno
			rm -f *.gcda

fclean:		clean
			rm -f $(NAME)
			rm -f $(BIN)

re:			fclean all

unit_tests:	re
			gcc -o $(BIN) $(TEST) $(OBJ) $(CFLAGS)

run_test:	unit_tests
			./$(BIN)

debug:		$(OBJ)
			gcc -o $(NAME) $(OBJ) $(CFLAGS) $(DEBUGFL)

.PHONY	=	all clean fclean re unit_tests run_test debug
