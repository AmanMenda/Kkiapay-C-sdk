##
## EPITECH PROJECT, 2022
## Makefile C
## File description:
## GNUmakefile
##

SRC	=	src/data.c \
		src/kkiapay.c \
		src/request_header.c \
		src/test_kkiapay.c

OBJ	=	$(SRC:.c=.o)

TEST_SRC	=	src/data.c \
				src/kkiapay.c \
				src/request_header.c \
				tests/test_get_private_key.c \
				tests/test_get_public_key.c \
				tests/test_get_secret.c \
				tests/test_retrieve_infos.c \
				tests/test_init_values.c \
				tests/test_verify_transaction.c

TEST_OBJ	=	$(TEST_SRC:.c=.o)

TEST_NAME	=	units_tests

NAME	=	Kkiapay-sdk

all:	$(NAME)

%.o:	%.c
	gcc -c $< -o $@ -g3

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) -g3 -lcurl -lcrypto

clean:
	-rm -f src/$(OBJ)

fclean:	clean
	-rm -f $(NAME)
	-rm -f src/*~
	-rm -f src/*#
	-rm -f vgcore.*
	-rm -f *.gcda
	-rm -f *.gcno
	-rm -f $(TEST_NAME)

re:	fclean all

tests_run:	 $(TEST_SRC)
	gcc -o $(TEST_NAME) $(TEST_SRC) -g3 --coverage -lcriterion -lcurl -lcrypto
	./$(TEST_NAME)
	gcovr --exclude tests/

.PHONY:	clean fclean all re