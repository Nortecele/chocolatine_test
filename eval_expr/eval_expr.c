/*
** EPITECH PROJECT, 2021
** EvalExpr
** File description:
** eval_expr.c
*/

#include "bistromatic.h"
#include <stdlib.h>

static char *factors(char **str_ptr, char *nb, char const *base)
{
    while (*str_ptr[0] == '*' || *str_ptr[0] == '/' || *str_ptr[0] == '%') {
        if (*str_ptr[0] == '*')
            nb = infin_mult(my_strdup(nb),
                            my_strtol(*str_ptr, str_ptr, base), base);
        else if (*str_ptr[0] == '/')
            nb = infin_div(nb, my_strtol(*str_ptr, str_ptr, base), base);
        else
            nb = infin_mod(nb, my_strtol(*str_ptr, str_ptr, base), base);
    }
    return nb;
}

static char *summands(char **str_ptr, char const *base)
{
    char *nb;
    char *factors_result;

    if (*str_ptr[0] == '\0')
        return "0";
    nb = my_strtol(*str_ptr, str_ptr, base);
    if (*str_ptr[0] == '*' || *str_ptr[0] == '/' || *str_ptr[0] == '%') {
        factors_result = factors(str_ptr, nb, base);
        return infin_add(factors_result, summands(str_ptr, base), base);
    }
    return infin_add(nb, summands(str_ptr, base), base);
}

static char *resolve_sub(char *str, int start, int end, char const *base)
{
    int j = 0;
    char *sub_result;
    char *sub;
    char *result;

    sub = malloc(sizeof(char) * end - start);
    sub[end - start - 1] = '\0';
    for (int i = start + 1; i < end; i++, j++) {
        sub[j] = str[i];
        str[i] = ' ';
    }
    result = summands(&sub, base);
    j = 0;
    for (int i = start; result[j] != '\0'; i++, j++)
        str[i] = result[j];
    return str;
}

static char *resolve(char *str, char const *base)
{
    int start = 0;
    int end = 0;

    while (1) {
        start = 0;
        end = 0;
        while (str[end] != '\0' && str[end] != ')')
            end++;
        if (end == my_strlen(str))
            return str;
        start = end;
        while (str[start] != '(')
            start--;
        str[start] = ' ';
        str[end] = ' ';
        str = remove_space(resolve_sub(str, start, end, base));
    }
}

char *eval_expr(char const *base, char const *ops,
                char const *expr, unsigned int size)
{
    char *clean_str = remove_space(my_strdup(expr));

    clean_str = resolve(clean_str, base);
    return (summands(&clean_str, base));
}
