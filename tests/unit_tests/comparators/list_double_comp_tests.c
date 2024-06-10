/*
** EPITECH PROJECT, 2024
** linked
** File description:
** list_double_comp_tests
*/

#include <criterion/criterion.h>
#include "linked.h"

Test(list_double_eq, test_list_double_eq)
{
    double a = 1.0;
    double b = 1.0;

    cr_assert_eq(list_double_eq(&a, &b), true);
}

Test(list_double_eq, test_list_double_eq_false)
{
    double a = 1.0;
    double b = 2.0;

    cr_assert_eq(list_double_eq(&a, &b), false);
}

Test(list_double_eq, test_list_double_eq_null)
{
    cr_assert_eq(list_double_eq(NULL, NULL), false);
}

Test(list_double_gt, test_list_double_gt)
{
    double a = 1.0;
    double b = 0.0;

    cr_assert_eq(list_double_gt(&a, &b), true);
}

Test(list_double_gt, test_list_double_gt_false)
{
    double a = 1.0;
    double b = 2.0;

    cr_assert_eq(list_double_gt(&a, &b), false);
}

Test(list_double_gt, test_list_double_gt_null)
{
    cr_assert_eq(list_double_gt(NULL, NULL), false);
}

Test(list_double_lt, test_list_double_lt)
{
    double a = 1.0;
    double b = 2.0;

    cr_assert_eq(list_double_lt(&a, &b), true);
}

Test(list_double_lt, test_list_double_lt_false)
{
    double a = 1.0;
    double b = 0.0;

    cr_assert_eq(list_double_lt(&a, &b), false);
}
