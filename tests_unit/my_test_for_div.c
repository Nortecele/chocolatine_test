/*
** EPITECH PROJECT, 2021
** bistro
** File description:
** tests
*/

#include "my.h"
#include "bistromatic.h"
#include <criterion/criterion.h>

Test(infin_div, easy_div)
{
    cr_assert_str_eq(infin_div("5", "5", "0123456789"), "1");
}

Test(infin_div, easy_div_neg)
{
    cr_assert_str_eq(infin_div("5", "-5", "0123456789"), "1");
}

Test(infin_div, hard_div)
{
    cr_assert_str_eq(infin_div("555", "105", "0123456789"), "5");
}

Test(infin_div, neg_by_neg_div)
{
    cr_assert_str_eq(infin_div("-456", "-4565", "0123456789"), "0");
}
