/*
** EPITECH PROJECT, 2021
** BISTROMATIC
** File description:
** infin_div
*/

#include "bistromatic.h"
#include <stdlib.h>

static char *add_zeros(char *divider, char *tmp_divider,
char *quotient, char const *base)
{
    if (is_greater(divider, tmp_divider) > 0)
        for (int i = 0; i < my_strlen(divider) - my_strlen(tmp_divider); i++)
            quotient = infin_mult(quotient, "10", base);
    return quotient;
}

static char *compute_remainder(char const *nbr1, char const* nbr2,
char const *base)
{
    char *dividend = my_strdup(nbr1); char *divider = my_strdup(nbr2);
    char *tmp_divider = my_strdup(nbr2);
    char *tmp_quotient, *quotient = "0"; int minus = 0;
    dividend = dividend[0] == '-' ? &dividend[1] : dividend;
    minus += nbr1[0] == '-' ? 1 : 0;
    divider = divider[0] == '-' ? &divider[1] : divider;
    tmp_divider = tmp_divider[0] == '-' ? &tmp_divider[1] : tmp_divider;
    while (is_greater(dividend, tmp_divider) >= 0) {
        tmp_quotient = "0";
        while (is_greater(dividend, infin_mult(divider, "10", base)) >= 0)
            divider = infin_mult(divider, "10", base);
        while (is_greater(dividend, divider) >= 0) {
            dividend = infin_sub(dividend, divider, base);
            tmp_quotient = infin_add(tmp_quotient, "1", base);
        }
        quotient = infin_add(quotient, tmp_quotient, base);
        quotient = add_zeros(divider, tmp_divider, quotient, base);
        divider = tmp_divider;
    }
    dividend = minus % 2 != 0 ? infin_mult(dividend, "-1", base) : dividend;
    return dividend;
}

char *infin_mod(char const *str1, char const *str2, char const *base)
{
    char *result;

    if (my_strcmp(str2, "0") == 0) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_USAGE);
    }
    result = compute_remainder(str1, str2, base);
    return (result);
}
