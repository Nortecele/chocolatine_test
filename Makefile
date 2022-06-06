##
## EPITECH PROJECT, 2021
## FinalStumper -> Makefile
## File description:
## Makefile
##

SRC     =	main.c eval_expr/*.c infin_add/*.c infin_mult/*.c infin_div/*.c \
		bistro_utils/*.c

NAME    =       calc

HEADER  =       include/

LIB_PATH = 	lib/my/

LIB = 		my

all:    fclean build_lib build clean

build:
	gcc $(SRC) -L$(LIB_PATH) -l$(LIB) -I $(HEADER) -o $(NAME)

clean:
	rm -f *~ '#'*
	rm -f tests_unit/*.gcda
	rm -f tests_unit/*.gcno
	rm -f tests_unit/unit_tests

fclean: clean
	rm -f $(NAME)

build_lib:
	(cd lib/my/ && make)

test_run:
	(cd tests_unit && make)
	(cd tests_unit && rm unit_tests-my_test*.gcda)
	(cd tests_unit && rm unit_tests-my_test*.gcno)

re: fclean all

.PHONY: all build clean fclean test_run re
