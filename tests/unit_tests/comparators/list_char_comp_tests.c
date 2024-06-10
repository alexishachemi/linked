/*
** EPITECH PROJECT, 2024
** linked
** File description:
** list_char_comp_tests
*/

#include <criterion/criterion.h>
#include "linked_dev.h"

Test(list_char_eq, test_list_char_eq)
{
    char a = 'a';
    char b = 'a';

    cr_assert_eq(list_char_eq(&a, &b), true);
}

Test(list_char_eq, test_list_char_eq_false)
{
    char a = 'a';
    char b = 'b';

    cr_assert_eq(list_char_eq(&a, &b), false);
}

Test(list_char_eq, test_list_char_eq_null)
{
    cr_assert_eq(list_char_eq(NULL, NULL), false);
}

Test(list_char_gt, test_list_char_gt)
{
    char a = 'b';
    char b = 'a';

    cr_assert_eq(list_char_gt(&a, &b), true);
}

Test(list_char_gt, test_list_char_gt_false)
{
    char a = 'a';
    char b = 'b';

    cr_assert_eq(list_char_gt(&a, &b), false);
}

Test(list_char_gt, test_list_char_gt_null)
{
    cr_assert_eq(list_char_gt(NULL, NULL), false);
}

Test(list_char_lt, test_list_char_lt)
{
    char a = 'a';
    char b = 'b';

    cr_assert_eq(list_char_lt(&a, &b), true);
}

Test(list_char_lt, test_list_char_lt_false)
{
    char a = 'b';
    char b = 'a';

    cr_assert_eq(list_char_lt(&a, &b), false);
}

Test(list_char_lt, test_list_char_lt_null)
{
    cr_assert_eq(list_char_lt(NULL, NULL), false);
}
