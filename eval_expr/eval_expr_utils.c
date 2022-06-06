/*
** EPITECH PROJECT, 2021
** EvalExpr
** File description:
** eval_expr_utils.c
*/

#include "bistromatic.h"
#include <stdlib.h>

int is_num(char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    return (0);
}

char *remove_space(char *str)
{
    int j = 0;
    char *tmp = malloc(sizeof(char) * my_strlen(str) + 1);

    for (int i = 0; str[i] != '\0'; i += 1) {
        tmp[j] = str[i] != ' ' ? str[i] : tmp[j];
        j += str[i] != ' ' ? 1 : 0;
    }
    tmp[j] = '\0';
    return tmp;
}

char *my_itoa(int nb)
{
    char *str;
    int tmp_nb = nb;
    int nb_len = 1;
    int size;

    for (; ABS(tmp_nb) >= 10; nb_len++)
        tmp_nb /= 10;
    size = nb >= 0 ? nb_len + 1 : nb_len + 2;
    str = malloc(sizeof(char) * size);
    str[size - 1] = '\0';
    str[size - 2] = nb >= 0 ? ' ' : '-';
    for (int i = 0; i < nb_len; i++, nb /= 10)
        str[i] = ABS(nb) % 10 + '0';
    return my_revstr(str);
}

char *my_strtol(char *str, char **endptr, char const *base)
{
    int i = 0;
    int len = my_strlen(base);
    char *nb;
    char c_base[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    c_base[len] = '\0';
    if (endptr == NULL)
        return nb;
    if (str[0] == '*' || str[0] == '/' || str[0] == '%')
        i++;
    nb = isolate_nbr(&str[i], c_base);
    for (; str[i] != '\0'; i += 1)
        if (in_base(str[i], c_base) == 1 && in_base(str[i + 1], c_base) == 0)
            break;
    *endptr = &str[i + 1];
    return (nb);
}
