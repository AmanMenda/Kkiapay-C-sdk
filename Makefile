##
## EPITECH PROJECT, 2022
## Makefile C
## File description:
## GNUmakefile
##

SRC	=	$(shell find . -type f -name "*.c")

OBJ	=	$(SRC:.c=.o)

NAME	=	Kkiapay-sdk

all:	$(NAME)

%.o:	%.c
	gcc -c $< -o $@ -g3

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) -g3 -lcurl -lcrypto

clean:
	-rm -f $(OBJ)

fclean:	clean
	-rm -f $(NAME)
	-rm -f *~
	-rm -f *#
	-rm -f vgcore.*

re:	fclean all

.PHONY:	clean fclean all re