##
## EPITECH PROJECT, 2021
## bistro
## File description:
## test mult
##

SRC =		../infin_mult/infin_mult.c	\
			../infin_add/infin_add.c	\
			../infin_add/infin_sub.c	\
			../infin_add/clean_result.c	\
			../infin_div/infin_div.c	\
			../infin_div/infin_mod.c

SRC_TEST = 	my_test_for_mult.c			\
			my_test_for_add.c			\
			my_test_for_div.c			\
			my_test_for_mod.c			\

NAME_TEST = unit_tests

INC			=	-I ../include -L ../lib -lmy

CRIT		=	-lcriterion --coverage

all:
	gcc -o $(NAME_TEST) $(SRC) $(SRC_TEST) $(INC) $(CRIT)
	./$(NAME_TEST)
