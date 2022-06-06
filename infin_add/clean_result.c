/*
** EPITECH PROJECT, 2021
** InfinADd
** File description:
** clean_result
*/

#include "bistromatic.h"

char *clean_result(char const *result)
{
    char *tmp_result = my_revstr(my_strdup(result));
    int i = 0;

    while (tmp_result[i] == '0')
        i += 1;
    tmp_result = &tmp_result[i];
    return tmp_result;
}
