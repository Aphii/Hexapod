##
## PERSONAL PROJECT, 2020
## hub-hexapod
## File description:
## Makefile
##

SRC_DIR		=	$(realpath src)

SRC_FILES	=	main.c		\
			hexapod.c	\

SRC		=	$(addprefix $(SRC_DIR)/, $(SRC_FILES)) \

OBJ		=	$(SRC:%.c=%.o)

NAME		=	hexapod

INCLUDE		=	-I include \

CFLAGS		=	-Wall -Wextra
CFLAGS		+=	$(INCLUDE)

CC		=	gcc

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

debug:		CFLAGS += -g
debug:		re
