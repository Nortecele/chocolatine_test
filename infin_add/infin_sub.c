/*
** EPITECH PROJECT, 2021
** InfinAdd
** File description:
** infin_sub
*/

#include "bistromatic.h"
#include <stdlib.h>

static void compute_acc(char *greater, int nbr1, int nbr2, int i)
{
    int len = my_strlen(greater);
    for (int j = i + 1; j < len && nbr1 < nbr2; j += 1) {
        if (greater[j] == '0') {
            greater[j] = '9';
        } else {
            greater[j] -= 1;
            break;
        }
    }
}

static char *make_sub(char *greater, char *smaller, int len, char const *base)
{
    char *result = malloc(sizeof(char) * len + 1);
    int tmp;
    int base_len = my_strlen(base);
    int offset = 7;

    for (int i = 0; i < len; i += 1) {
        int nbr1 = ATOD(greater[i]);
        int nbr2 = ATOD(smaller[i]);
        nbr1 -= nbr1 > 9 ? offset : 0;
        nbr2 -= nbr2 > 9 ? offset : 0;
        compute_acc(greater, nbr1, nbr2, i);
        nbr1 += nbr1 < nbr2 ? base_len : 0;
        tmp = nbr1 - nbr2;
        if (tmp > base_len - 1)
            tmp = (tmp + (10 - base_len)) / 10;
        if (tmp > 9)
            result[i] = DTOA(tmp) + offset;
        else
            result[i] = DTOA(tmp);
    }
    result[len] = '\0';
    return result;
}

static char *pre_sub(char *greater, char *smaller, char const *base)
{
    int max_len = my_strlen(greater);
    int min_len = my_strlen(smaller);
    char *smaller1 = malloc(sizeof(char) * max_len + 1);

    my_strcpy(smaller1, my_revstr(smaller));
    for (int i = min_len; i < max_len + 1; i += 1)
        smaller1[i] = '0';
    smaller1[max_len] = '\0';
    return make_sub(my_revstr(greater), smaller1, max_len, base);
}

static char *do_infin_sub(char const *str1, char const *str2,
char *minus, char const *base)
{
    char *result, *bigger, *smaller, *c_minus;
    char *nbr1 = my_strdup(str1);
    char *nbr2 = my_strdup(str2);
    int nbr1_len = my_strlen(nbr1);
    int nbr2_len = my_strlen(nbr2);
    int add_minus = 0;

    if (my_strcmp(nbr1, nbr2) == 0)
        return "0";
    if (nbr1_len == nbr2_len) {
        bigger = my_strcmp(nbr1, nbr2) > 0 ? nbr1 : nbr2;
        smaller = my_strcmp(nbr1, nbr2) > 0 ? nbr2 : nbr1;
    } else {
        bigger = nbr1_len > nbr2_len ? nbr1 : nbr2;
        smaller = nbr1_len > nbr2_len ? nbr2 : nbr1;
    }
    add_minus = my_strcmp(bigger, minus) == 0 ? 1 : 0;
    result = clean_result(pre_sub(bigger, smaller, base));
    c_minus = malloc(sizeof(char) * my_strlen(result) + 2);
    c_minus[0] = '-';
    return (add_minus == 1 ? my_strcat(c_minus, result) : result);
}

char *infin_sub(char const *str1, char const *str2, char const *base)
{
    char *nbr1 = my_strdup(str1);
    char *nbr2 = my_strdup(str2);
    char *n_nb;
    char *result;

    if (nbr1[0] == '-' && nbr2[0] == '-')
        result = do_infin_sub(&nbr2[1], &nbr1[1], my_strdup(&nbr1[1]), base);
    else if (nbr1[0] != '-' && nbr2[0] != '-')
        result = do_infin_sub(nbr1, nbr2, my_strdup(nbr2), base);

    if (nbr1[0] == '-' && nbr2[0] != '-') {
        n_nb = malloc(sizeof(char) * my_strlen(nbr2) + 2);
        n_nb[0] = '-';
        my_strcat(n_nb, nbr2);
        result = infin_add(nbr1, n_nb, base);
    } else if (nbr1[0] != '-' && nbr2[0] == '-')
        result = infin_add(nbr1, &nbr2[1], base);
    return result;
}
