/*
** EPITECH PROJECT, 2021
** bistro
** File description:
** tests
*/

#include "my.h"
#include "bistromatic.h"
#include <criterion/criterion.h>

Test(infin_add, easy_add)
{
    cr_assert_str_eq(infin_add("5", "5", "0123456789"), "10");
}

Test(infin_add, add_by_zero)
{
    cr_assert_str_eq(infin_add("5", "0", "0123456789"), "5");
}

Test(infin_add, easy_add_neg)
{
    cr_assert_str_eq(infin_add("5", "-5", "0123456789"), "0");
}

Test(infin_add, hard_add)
{
    cr_assert_str_eq(infin_add("555", "105", "0123456789"), "660");
}

Test(infin_add, great_infin_add)
{
    char *str = "1000000000000";
    char *str2 = "500000000000";
    cr_assert_str_eq(infin_add(str2, str2, "0123456789"), str);
}

Test(infin_add, infin_add_by_zero)
{
    char *str = "5555556548748416515696";
    cr_assert_str_eq(infin_add(str, "0", "0123456789"), str);
}

Test(infin_add, zero_by_infin_add)
{
    char *str = "-4515914985156159915194";
    cr_assert_str_eq(infin_add("0", str, "0123456789"), str);
}

Test(infin_add, neg_by_neg_add)
{
    cr_assert_str_eq(infin_add("-456", "-4565", "0123456789"), "-5021");
}