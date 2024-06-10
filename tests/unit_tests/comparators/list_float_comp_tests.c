/*
** EPITECH PROJECT, 2024
** linked
** File description:
** list_float_comp_tests
*/

#include <criterion/criterion.h>
#include "linked_dev.h"

Test(list_float_eq, test_list_float_eq)
{
    float a = 1.0;
    float b = 1.0;

    cr_assert_eq(list_float_eq(&a, &b), true);
}

Test(list_float_eq, test_list_float_eq_false)
{
    float a = 1.0;
    float b = 2.0;

    cr_assert_eq(list_float_eq(&a, &b), false);
}

Test(list_float_eq, test_list_float_eq_null)
{
    cr_assert_eq(list_float_eq(NULL, NULL), false);
}

Test(list_float_gt, test_list_float_gt)
{
    float a = 1.0;
    float b = 0.0;

    cr_assert_eq(list_float_gt(&a, &b), true);
}

Test(list_float_gt, test_list_float_gt_false)
{
    float a = 1.0;
    float b = 2.0;

    cr_assert_eq(list_float_gt(&a, &b), false);
}

Test(list_float_gt, test_list_float_gt_null)
{
    cr_assert_eq(list_float_gt(NULL, NULL), false);
}

Test(list_float_lt, test_list_float_lt)
{
    float a = 1.0;
    float b = 2.0;

    cr_assert_eq(list_float_lt(&a, &b), true);
}

Test(list_float_lt, test_list_float_lt_false)
{
    float a = 2.0;
    float b = 1.0;

    cr_assert_eq(list_float_lt(&a, &b), false);
}

Test(list_float_lt, test_list_float_lt_null)
{
    cr_assert_eq(list_float_lt(NULL, NULL), false);
}
