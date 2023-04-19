##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## A Makefile that compiles both json parser and writer libraries
##

NAME = libjson.a

all:	$(NAME)

$(NAME):
		make -C json_parser/
		make -C json_writer/
		cp json_parser/libjson_parser.a ./libjson.a
		ar -x json_writer/libjson_writer.a
		ar -rcs libjson.a *.o

clean:
		make clean -C json_parser/
		make clean -C json_writer/
		rm -f *.o

fclean:		clean
		make fclean -C json_parser/
		make fclean -C json_writer/
		rm -f $(NAME)

re:		fclean 	$(NAME)
		make fclean -C json_parser/
		make fclean -C json_writer/
		rm -f *.o
