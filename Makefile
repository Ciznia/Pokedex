## EPITECH PROJECT, 2022
## make
## File description:
## desc
##

SRC = 	\
	src/main.c \
	src/window/window_manager.c \
	src/window/events/events_manager.c \
	src/window/events/events_add.c \
	src/sprite/new_sprite.c \
	src/text/new_text.c \
	src/window/init/init_arrow.c \
	src/utils/is_mouse_click.c \
	src/events/arrow_click.c \

OBJ = $(SRC:.c=.o)

INCLUDE_FLAGS = \
	-I include\
	-I library/tools_box/include\

C_WARNING_FLAGS = -Wextra -Wall
C_FLAGS = $(C_WARNING_FLAGS) $(INCLUDE_FLAGS)

# Library
LIB_FLAGS = \
	-lm \
	-lcsfml-graphics -lcsfml-window -lcsfml-system\
	-L library/tools_box -l:tools_box.a

NAME = my_pokedex

GCC = gcc

all: $(NAME)

.c.o:
	@echo "$(notdir $(CURDIR)): C '$<'"
	@$(GCC) $(C_FLAGS) -c -o $*.o $<

$(NAME): tools_box $(OBJ)
	@$(GCC) -o $@ $(OBJ) $(INCLUDE_FLAGS) $(LIB_FLAGS)
.PHONY: $(NAME)

clean:
	@rm -f $(OBJ)
.PHONY: clean

fclean: clean
	@rm -f $(NAME)
.PHONY: fclean

re: fclean all
.PHONY: re

### Library ###
tools_box:
	make -C library/tools_box