/*
** EPITECH PROJECT, 2024
** linked
** File description:
** list_str_comp_tests
*/

#include <criterion/criterion.h>
#include "linked_dev.h"

Test(list_str_eq, test_list_str_eq)
{
    char *str1 = "Hello";
    char *str2 = "Hello";

    cr_assert_eq(list_str_eq(str1, str2), true);
}

Test(list_str_eq, test_list_str_eq_false)
{
    char *str1 = "Hello";
    char *str2 = "World";

    cr_assert_eq(list_str_eq(str1, str2), false);
}

Test(list_str_eq, test_list_str_eq_null)
{
    cr_assert_eq(list_str_eq(NULL, NULL), false);
}
