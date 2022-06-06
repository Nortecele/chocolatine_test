/*
** EPITECH PROJECT, 2021
** bistro
** File description:
** test
*/

#include "my.h"
#include "bistromatic.h"
#include <criterion/criterion.h>

Test(infin_mult, easy_mult)
{
    cr_assert_str_eq(infin_mult("5", "5", "0123456789"), "25");
}

Test(infin_mult, mult_by_zero)
{
    cr_assert_str_eq(infin_mult("5", "0", "0123456789"), "0");
}

Test(infin_mult, easy_mult_neg)
{
    cr_assert_str_eq(infin_mult("5", "-5", "0123456789"), "-25");
}

Test(infin_mult, hard_mult)
{
    cr_assert_str_eq(infin_mult("555", "105", "0123456789"), "58275");
}

Test(infin_mult, great_infin_mult)
{
    char *str = "250000000000000000000000";
    char *str2 = "500000000000";
    cr_assert_str_eq(infin_mult(str2, str2, "0123456789"), str);
}

Test(infin_mult, infin_mult_by_zero)
{
    char *str = "5555556548748416515696";
    cr_assert_str_eq(infin_mult(str, "0", "0123456789"), "0");
}

Test(infin_mult, zero_by_infin_mult)
{
    char *str = "-4515914985156159915194";
    cr_assert_str_eq(infin_mult("0", str, "0123456789"), "0");
}

Test(infin_mult, neg_by_neg_mult)
{
    cr_assert_str_eq(infin_mult("-456", "-4565", "0123456789"), "2081640");
}
