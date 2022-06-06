/*
** EPITECH PROJECT, 2021
** Bistromatic -> BISTROMATIC.H
** File description:
** bistromatic.h
*/

#include "my.h"

#ifndef BISTO_H
    #define BISTRO_H

    #define OP_OPEN_PARENT_IDX  0
    #define OP_CLOSE_PARENT_IDX 1
    #define OP_PLUS_IDX         2
    #define OP_SUB_IDX          3
    #define OP_NEG_IDX          3
    #define OP_MULT_IDX         4
    #define OP_DIV_IDX          5
    #define OP_MOD_IDX          6

    #define EXIT_USAGE    84
    #define EXIT_BASE     84
    #define EXIT_SIZE_NEG 84
    #define EXIT_MALLOC   84
    #define EXIT_READ     84
    #define EXIT_OPS      84

    #define SYNTAX_ERROR_MSG "syntax error"
    #define ERROR_MSG        "error"

    #define ABS(x)  (x < 0 ? x * (-1) : x)
    #define ATOD(x) (x - '0')
    #define DTOA(x) (x + '0')

char *eval_expr(char const *base, char const *ops,
                char const *expr, unsigned int size);
char *infin_mult(char const *str1, char const *str2, char const *base);
char *infin_div(char const *str1, char const *str2, char const *base);
char *infin_mod(char const *str1, char const *str2, char const *base);
char *infin_add(char const *str1, char const *str2, char const *base);
char *infin_sub(char const *str1, char const *str2, char const *base);
char *replace_op(char *str, char *caracters);
char *replace_num(char *str, char const* base, char const *op);
char *convert_result(char *str, char const* base);
int is_num(char c);
char *remove_space(char *str);
char *my_strtol(char *str, char **endptr, char const *base);
char *my_itoa(int nb);
char *clean_result(char const *result);
void check_ops(char const *ops);
void check_base(char const *b, char const *op);
void check_expr(char *expr, char *ops, char *base);
char *isolate_nbr(char const *str, char const *base);
int in_base(char c, char const *base);
int is_greater(char *nbr1, char *nbr2);

#endif
