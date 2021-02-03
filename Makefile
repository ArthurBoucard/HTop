##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

SRC	=	$(wildcard */*.cpp)

NAME	=	MyGKrellm

OBJ	=	$(SRC:.c=.o)

CC	=	g++
LFLAGS	=	-L./lib -lmy
MFLAGS	=	-C./lib/my
CFLAGS	=	-I./inc\
			-lncurses\
			-lsfml-graphics -lsfml-window -lsfml-system
WFLAGS  =	-Wall\
			-Wextra\
			-Werror\

all:	$(NAME)

END		+=	\e[0m"
CBLUE	+=	"\e[1;34m
CRED	+=	"\x1b[31m

$(NAME):	$(OBJ)
	@echo -e $(CBLUE)======[COMPILING]=====$(END)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) -ggdb3
	rm -f *.o
	@echo -e $(CBLUE)======[COMPILED]=====$(END)

clean:
	@echo -e $(CRED)======[CLEANING]=====$(END)
	rm -f $(NAME)
	rm -f *.o
	rm -f vgcore.*
	@echo -e $(CRED)======[CLEANED]=====$(END)

fclean:	clean

re:	fclean all

%.o: %.c
	gcc -o $@ -c $< $(CFLAGS)
