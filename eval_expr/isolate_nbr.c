/*
** EPITECH PROJECT, 2021
** BISTRO
** File description:
** isolate nbr
*/

#include "bistromatic.h"
#include <stdlib.h>

int in_base(char c, char const *base)
{
    for (int i = 0; i < my_strlen(base); i++)
        if (c == base[i])
            return 1;
    return 0;
}

char *isolate_nbr(char const *str, char const *base)
{
    char *nbr = malloc(sizeof(char) * my_strlen(str) + 1);
    int i = 0;
    int j = 0;
    int minus = 0;

    while (str[i] == '+' || str[i] == '-') {
        if (str[i] == '-')
            minus++;
        i++;
    }
    if ((minus % 2) != 0) {
        nbr[0] = '-';
        j++;
    }
    if (i == 0 && in_base(str[0], base) == 0)
        return "0";
    for (; in_base(str[i], base) == 1; i++, j++)
        nbr[j] = str[i];
    nbr[j] = '\0';
    return nbr;
}
