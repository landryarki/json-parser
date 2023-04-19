##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## A Makefile that compiles my json parser library
##

SRC		=		advance_fd.c 	\
				extract_json.c 	\
				get_json_basic.c 	\
				get_json_object_bis.c 	\
				get_json_object.c 	\
				json_error.c 	\
				json_get_from_array.c 	\
				json_guide.c 	\
				json_set_data_array.c 	\
				json_set_data_bis.c 	\
				json_set_data.c 	\
				parser_json.c		\
				my_put_nbr.c	\
				my_puterr.c	\
				my_strcat.c	\


OBJ		=		$(SRC:.c=.o)

NAME	=		libjson_parser.a

all:	$(NAME)

$(NAME):	$(OBJ)
		ar rc $(NAME) $(OBJ)

clean:
		rm -f *.o

fclean:		clean
		rm -f $(NAME)

re:		fclean 	$(NAME)
		rm -f $(OBJ)
