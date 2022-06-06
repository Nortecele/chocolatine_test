/*
** EPITECH PROJECT, 2021
** InfinAdd
** File description:
** add infinite
*/

#include "bistromatic.h"
#include <stdlib.h>

static char *make_add(char const *nbr1, char const *nbr2,
int len, char const *base)
{
    char *result;
    int tmp, acc, nb1, nb2;
    int base_len = my_strlen(base);

    acc = 0;
    result = malloc(sizeof(char) * len);
    for (int i = 0; i < len - 1; i += 1) {
        nb1 = ATOD(nbr1[i]);
        nb2 = ATOD(nbr2[i]);
        nb1 -= nb1 > 9 ? 7 : 0;
        nb2 -= nb2 > 9 ? 7 : 0;
        tmp = nb1 + nb2 + acc;
        acc = 0;
        if (tmp > base_len - 1) {
            acc = (tmp + (10 - base_len)) / 10;
            tmp = (tmp + (10 - base_len)) % 10;
        }
        result[i] = tmp > 9 ? DTOA(tmp) + 7 : DTOA(tmp);
    }
    result[len - 1] = '\0';
    return result;
}

static char *pre_add(char *greater, char *smaller, char const *base)
{
    int max_len = my_strlen(greater);
    int min_len = my_strlen(smaller);
    char *greater1 = malloc(sizeof(char) * max_len + 2);
    char *smaller1 = malloc(sizeof(char) * max_len + 2);

    my_strcpy(greater1, my_revstr(greater));
    greater1[max_len] = '0';
    greater1[max_len + 1] = '\0';
    my_strcpy(smaller1, my_revstr(smaller));
    for (int i = min_len; i < max_len + 2; i += 1)
        smaller1[i] = '0';
    smaller1[max_len + 1] = '\0';
    return make_add(greater1, smaller1, max_len + 2, base);
}

static char *do_infin_add(char const *str1, char const *str2,
int minus, char const *base)
{
    char *result;
    char *nbr1 = my_strdup(str1);
    char *nbr2 = my_strdup(str2);
    char *bigger;
    char *smaller;
    int nbr1_len = my_strlen(nbr1);
    int nbr2_len = my_strlen(nbr2);
    char c_minus[] = "-";

    if (my_strcmp(str1, "0") == 0 && my_strcmp(str2, "0") == 0)
        return "0";
    if (nbr1_len == nbr2_len) {
        bigger = my_strcmp(nbr1, nbr2) > 0 ? nbr1 : nbr2;
        smaller = my_strcmp(nbr1, nbr2) > 0 ? nbr2 : nbr1;
    } else {
        bigger = nbr1_len > nbr2_len ? nbr1 : nbr2;
        smaller = nbr1_len > nbr2_len ? nbr2 : nbr1;
    }
    result = clean_result(pre_add(bigger, smaller, base));
    return (minus == 1 ? my_strcat(my_strdup(c_minus), result) : result);
}

char *infin_add(char const *str1, char const *str2, char const *base)
{
    char *nbr1 = my_strdup(str1);
    char *nbr2 = my_strdup(str2);
    char *result;

    if (nbr1[0] == '-' && nbr2[0] == '-')
        result = do_infin_add(&nbr1[1], &nbr2[1], 1, base);
    else if (nbr1[0] != '-' && nbr2[0] != '-')
        result = do_infin_add(nbr1, nbr2, 0, base);

    if (nbr1[0] == '-' && nbr2[0] != '-')
        result = infin_sub(nbr2, &nbr1[1], base);
    else if (nbr1[0] != '-' && nbr2[0] == '-')
        result = infin_sub(nbr1, &nbr2[1], base);
    return (result);
}
