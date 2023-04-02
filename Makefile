##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Builds a libmy_malloc.so file
##

RM			=	rm -f
CC			=	gcc
CFLAGS			+=	-fPIC -Wall -Wextra -pedantic -O1
CPPFLAGS		+=	-I "include/"

NAME			=	libmy_malloc.so

SRC			=	malloc.c		\
				realloc.c		\
				wesh.c			\
				opti.c

OBJ			=	$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -shared -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re debug
