/*
** EPITECH PROJECT, 2021
** BISTROMATIC
** File description:
** infin_mult
*/

#include "bistromatic.h"
#include <stdlib.h>

static char *fill_string(char *string, int len)
{
    for (int i = 0; i < len; i++)
        string[i] = '0';
    return string;
}

static char *calculs_mult(char *tmp, char *string1,
char *string2, char const *base)
{
    int j, add, i, result = 0;
    int len2 = my_strlen(string2);
    int len1 = my_strlen(string1);
    int len = len1 + len2;
    int nb1, nb2, curr_acc, next_acc;

    fill_string(tmp, len);
    for (j = 0; j < len1; j++) {
        result = 0;
        for (i = 0; i < len2; i++) {
            nb1 = ATOD(string1[j]) - (ATOD(string1[j]) > 9 ? 7 : 0);
            nb2 = ATOD(string2[i]) - (ATOD(string2[i]) > 9 ? 7 : 0);
            curr_acc = ATOD(tmp[j + i]) - (ATOD(tmp[j + i]) > 9 ? 7 : 0);
            result = nb1 * nb2 + curr_acc;
            nb1 = result % my_strlen(base);
            nb2 = result / my_strlen(base) + ATOD(tmp[j + i + 1]);
            tmp[j + i] = nb1 > 9 ? DTOA(nb1) + 7 : DTOA(nb1);
            tmp[j + i + 1] = nb2 > 9 ? DTOA(nb2) + 7 : DTOA(nb2);
        }
    }
    return my_revstr(tmp);
}

static char *clean_string(char *str, char *string)
{
    if (str[0] == '-')
        for (int i = 1; str[i] != '\0'; i++)
            string[i - 1] = str[i];
    else
        my_strcpy(string, str);
    return my_revstr(string);
}

static char *apply_sign(char *tmp, int sign)
{
    int a = 0;
    char *tmp2 = malloc(sizeof(char) * my_strlen(tmp) + 1);

    while (tmp[a] == '0' && a < my_strlen(tmp) - 1)
        a++;
    for (int i = 0; tmp[a] != '\0'; a++, i++)
        tmp2[i] = tmp[a];
    if (sign == 1 && tmp2[0] != '0') {
        my_revstr(tmp2);
        tmp2[my_strlen(tmp2)] = '-';
        my_revstr(tmp2);
    }
    return tmp2;
}

char *infin_mult(char const *nbr1, char const *nbr2, char const *base)
{
    char *str1 = my_strdup(nbr1);
    char *str2 = my_strdup(nbr2);
    int len1 = my_strlen(str1);
    int len2 = my_strlen(str2);
    int len = len1 + len2;
    char *tmp = malloc(sizeof(char) * (len + 1));
    char *string1 = malloc(sizeof(char) * (len + 2));
    char *string2 = malloc(sizeof(char) * (len + 2));
    int sign = 0;

    if ((str1[0] == '-' && str2[0] != '-')
        || (str2[0] == '-' && str1[0] != '-'))
        sign = 1;
    clean_string(str1, string1);
    clean_string(str2, string2);
    tmp = calculs_mult(tmp, string1, string2, base);
    tmp = apply_sign(tmp, sign);
    free(string2);
    free(string1);
    return tmp;
}
