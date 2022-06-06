/*
** EPITECH PROJECT, 2021
** Bistromatic -> Error Handling
** File description:
** Error handling
*/

#include "my.h"
#include "bistromatic.h"
#include <stdlib.h>

static int check_doublons(char const *string, int i)
{
    for (int j = i + 1; j < my_strlen(string); j++)
        if (string[i] == string[j])
            return 1;
    return 0;
}

void check_ops(char const *ops)
{
    int cond;

    for (int i = 0; i < my_strlen(ops); i++)
        if (!cond)
            cond = check_doublons(ops, i);
    if (cond || my_strlen(ops) != 7) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_OPS);
    }
}

void check_base(char const *b, char const *op)
{
    int op_in_base = 0;
    int doublons = 0;

    for (int i = 0; b[i] != '\0'; i++) {
        doublons += check_doublons(b, i);
        for (int j = 0; op[j] != '\0'; j++)
            op_in_base += b[i] == op[j] ? 1 : 0;
    }
    if (op_in_base > 0 || doublons > 0) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_BASE);
    }
}

void check_invalid_car(int i, char *expr, char *op, char *base)
{
    int is_num = 0;
    int is_op = 0;

    for (int j = 0; j < my_strlen(base); j++)
        if (base[j] == expr[i])
            is_num = 1;
    for (int j = 0; j < my_strlen(op); j++)
        if (op[j] == expr[i])
            is_op = 1;
    if (is_num == 0 && is_op == 0) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_USAGE);
    }
}

void check_expr(char *expr, char *ops, char *base)
{
    int counter1 = 0;
    int counter2 = 0;

    for (int i = 0; i < my_strlen(expr); i++) {
        if (expr[i] == ops[0])
            counter1++;
        if (expr[i] == ops[1])
            counter2++;
    }
    if (counter1 != counter2) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_BASE);
    }

    for (int i = 0; i < my_strlen(expr); i++) {
        check_invalid_car(i, expr, ops, base);
    }
}
