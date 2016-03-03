##
## Makefile for makefile in /home/peau_c
##
## Made by
## Login   <peau_c@epitech.net>
##
## Started on  Wed Dec  9 12:17:54 2015
## Last update Thu Mar  3 09:29:17 2016 Clement Peau
##

SRC=		src/main.c \
		src/reading.c \
		src/my_strlen.c \
		src/parsing.c \
		src/getinfo.c \
		src/my_putstr.c \

OBJ=		$(SRC:.c=.o)

NAME=		bsq

CC=		gcc -g

CFLAGS=		-W -Werror -Wall -Wextra -ansi -pedantic

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ)

all:		$(NAME)

clean:
		rm -rf $(OBJ)

fclean:		clean
		rm -rf $(NAME)

re:		fclean all
