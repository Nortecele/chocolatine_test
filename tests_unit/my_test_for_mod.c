/*
** EPITECH PROJECT, 2021
** bistro
** File description:
** tests
*/

#include "my.h"
#include "bistromatic.h"
#include <criterion/criterion.h>

Test(infin_mod, easy_mod)
{
    cr_assert_str_eq(infin_mod("5", "5", "0123456789"), "0");
}

Test(infin_mod, easy_mod_neg)
{
    cr_assert_str_eq(infin_mod("5", "-5", "0123456789"), "0");
}

Test(infin_mod, hard_mod)
{
    cr_assert_str_eq(infin_mod("555", "105", "0123456789"), "30");
}

Test(infin_mod, neg_by_neg_mod)
{
    cr_assert_str_eq(infin_mod("-456", "-4565", "0123456789"), "-456");
}
