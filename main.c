/*
** EPITECH PROJECT, 2021
** Bistromatic -> MAIN.C
** File description:
** MAIN.C
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "bistromatic.h"




static char *get_expr(unsigned int size)
{
    char *expr;

    // TAMERE
    if (size <= 0) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_SIZE_NEG);
    }
    expr = malloc(size + 1);
    if (expr == 0) {
        my_putstr(ERROR_MSG);
        exit(EXIT_MALLOC);
    }
    if (read(0, expr, size) != size) {
        my_putstr(ERROR_MSG);
        exit(EXIT_READ);
    }
    expr[size] = 0;
    return (expr);
}

int main(int ac, char **av)
{
    unsigned int size;
    char *expr;
    char *result;

    if (ac != 4) {
        my_putstr("Usage: ");
        my_putstr(av[0]);
        my_putstr(" base ops\"()+_*/%\" exp_len\n");
        return (EXIT_USAGE);
    }
    check_base(av[1], av[2]);
    check_ops(av[2]);
    size = my_getnbr(av[3]);
    expr = get_expr(size);
    check_expr(expr, av[2], av[1]);
    replace_num(expr, av[1], av[2]);
    replace_op(expr, av[2]);
    result = eval_expr(av[1], av[2], expr, size);
    my_putstr(convert_result(result, av[1]));
    return (EXIT_SUCCESS);
}
