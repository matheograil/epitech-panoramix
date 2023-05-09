##
## EPITECH PROJECT, 2023
## Panoramix
## File description:
## MAKEFILE file.
##

SRC = main.c \
	sources/arguments/init.c \
	sources/parameters/init.c \
	sources/parameters/free.c \
	sources/pot/init.c \
	sources/druid/init.c \
	sources/print_help.c \
	sources/init_structures.c \
	sources/throw_errors.c \
	sources/utils/my_free.c \
	sources/villagers/init.c \
	sources/villagers/free.c \
	sources/villagers/add.c \
	sources/threads/druid.c \
	sources/threads/init.c \
	sources/threads/villager.c

OBJ = $(SRC:.c=.o)

CFLAGS += -pthread -Wall -Wextra -Werror -I ./includes

NAME = panoramix

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
