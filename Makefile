##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

CC      =       gcc

SRC     =	my_hunter_main.c \
		my_hunter_game.c \
		my_hunter_managment.c \
		my_hunter_create.c \
		my_hunter_check.c \
		my_hunter_display.c \
		my_hunter_duck.c \
		src/my_strcmp.c \
		src/my_putchar.c \
		src/my_putstr.c

OBJ     =       $(SRC:.c=.o)

NAME    =       my_hunter

CFLAGS  =       -W -Wall -ansi -pedantic -g -std=c99 -I include

all:    $(NAME)

$(NAME):        $(OBJ)
		$(CC) $(OBJ) -o $(NAME) $(CFLAGS) -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:     fclean all
