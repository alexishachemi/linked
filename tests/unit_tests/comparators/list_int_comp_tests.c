/*
** EPITECH PROJECT, 2024
** linked
** File description:
** list_int_comp_tests
*/

#include <criterion/criterion.h>
#include "linked_dev.h"

Test(list_int_eq, test_list_int_eq)
{
    int a = 5;
    int b = 5;

    cr_assert_eq(list_int_eq(&a, &b), true);
}

Test(list_int_eq, test_list_int_eq_false)
{
    int a = 5;
    int b = 6;

    cr_assert_eq(list_int_eq(&a, &b), false);
}

Test(list_int_eq, test_list_int_eq_null)
{
    cr_assert_eq(list_int_eq(NULL, NULL), false);
}

Test(list_int_gt, test_list_int_gt)
{
    int a = 5;
    int b = 4;

    cr_assert_eq(list_int_gt(&a, &b), true);
}

Test(list_int_gt, test_list_int_gt_false)
{
    int a = 5;
    int b = 6;

    cr_assert_eq(list_int_gt(&a, &b), false);
}

Test(list_int_gt, test_list_int_gt_null)
{
    cr_assert_eq(list_int_gt(NULL, NULL), false);
}

Test(list_int_lt, test_list_int_lt)
{
    int a = 5;
    int b = 6;

    cr_assert_eq(list_int_lt(&a, &b), true);
}

Test(list_int_lt, test_list_int_lt_false)
{
    int a = 5;
    int b = 4;

    cr_assert_eq(list_int_lt(&a, &b), false);
}

Test(list_int_lt, test_list_int_lt_null)
{
    cr_assert_eq(list_int_lt(NULL, NULL), false);
}
