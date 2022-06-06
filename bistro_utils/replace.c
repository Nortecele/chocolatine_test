/*
** EPITECH PROJECT, 2021
** Replace -> REPLACE.C
** File description:
** REPLACE.C
*/

#include "my.h"

char const original[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVXYZ";

static int index_in_base(char c, char const *base)
{
    for (int i = 0; base[i] != '\0'; i++)
        if (base[i] == c)
            return i;
    return -1;
}

static int is_op(char c, char const *op)
{
    for (int i = 0; op[i] != '\0'; i++)
        if (op[i] == c)
            return 1;
    return 0;
}

char *replace_op(char *str, char *caracters)
{
    char list[] = "()+-*/%";
    for (int i = 0; i < my_strlen(caracters); i++)
        for (int j = 0; j < my_strlen(str); j++)
            str[j] = (str[j] == caracters[i]) ? list[i] : str[j];
    return str;
}

char *replace_num(char *str, char const *base, char const *op)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (is_op(str[i], op) == 0)
            str[i] = original[index_in_base(str[i], base)];
    return str;
}

char *convert_result(char *str, char const *base)
{
    int i = 0;

    if (my_strcmp(str, "0") == 0)
        return str;
    if (str[0] == '-')
        i++;
    for (; str[i] != '\0'; i++)
        str[i] = base[index_in_base(str[i], original)];
    return str;
}
