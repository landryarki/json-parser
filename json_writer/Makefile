##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## A Makefile that compiles my json writer library
##

SRC		=		init_props.c	\
				json_create_props.c		\
				json_manipulation.c		\
				json_manipulation_bis.c		\
				writer_json.c			\
				writer_json_bis.c		\
				my_put_nbr.c	\
				my_puterr.c	\
				my_strcat.c	\


OBJ		=		$(SRC:.c=.o)

NAME	=		libjson_writer.a

all:	$(NAME)

$(NAME):	$(OBJ)
		ar rc $(NAME) $(OBJ)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean 	$(NAME)
