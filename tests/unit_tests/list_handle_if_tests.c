/*
** EPITECH PROJECT, 2024
** linked
** File description:
** list_handle_if_tests
*/

#include <criterion/criterion.h>
#include "linked_dev.h"
#include "test_utils.h"

Test(list_get_if, find_if_null_list)
{
    cr_assert_null(list_get_if(NULL, list_int_gt, NULL));
}

Test(list_get_if, find_if_null_compare)
{
    list_t *list = list_create();

    cr_assert_null(list_get_if(list, NULL, NULL));
    list_destroy(list, NULL);
}

Test(list_get_if, find_if_null_right)
{
    list_t *list = list_create();

    cr_assert_null(list_get_if(list, list_int_gt, NULL));
    list_destroy(list, NULL);
}

Test(list_get_if, find_if_empty_list)
{
    list_t *list = list_create();

    cr_assert_null(list_get_if(list, list_int_gt, NULL));
    list_destroy(list, NULL);
}

Test(list_get_if, find_if_no_match)
{
    list_t *list = list_create();
    int *data = list_add(list, allocate_int);
    int *data2 = list_add(list, allocate_int);

    *data = 1;
    *data2 = 2;
    cr_assert_null(list_get_if(list, list_int_gt, data2));
    list_destroy(list, destroy_int);
}

Test(list_get_if, find_if_match)
{
    list_t *list = list_create();
    int *data = list_add(list, allocate_int);
    int *data2 = list_add(list, allocate_int);

    *data = 1;
    *data2 = 2;
    cr_assert_eq(list_get_if(list, list_int_gt, data), data2);
    list_destroy(list, destroy_int);
}

Test(list_move_if, move_if_null_from)
{
    list_t *list = list_create();

    cr_assert_eq(list_move_if(NULL, list, list_int_gt, NULL), -1);
    list_destroy(list, NULL);
}

Test(list_move_if, move_if_null_to)
{
    list_t *list = list_create();

    cr_assert_eq(list_move_if(list, NULL, list_int_gt, NULL), -1);
    list_destroy(list, NULL);
}

Test(list_move_if, move_if_null_compare)
{
    list_t *list = list_create();

    cr_assert_eq(list_move_if(list, list, NULL, NULL), -1);
    list_destroy(list, NULL);
}

Test(list_move_if, move_if_null_right)
{
    list_t *list = list_create();

    cr_assert_eq(list_move_if(list, list, list_int_gt, NULL), -1);
    list_destroy(list, NULL);
}

Test(list_move_if, move_if_empty_list)
{
    list_t *list = list_create();
    list_t *list2 = list_create();
    int right = 1;

    cr_assert_eq(list_move_if(list, list2, list_int_gt, &right), 0);
    list_destroy(list, NULL);
    list_destroy(list2, NULL);
}

Test(list_move_if, move_if_no_match)
{
    list_t *list = list_create();
    list_t *list2 = list_create();
    int *data = list_add(list, allocate_int);
    int *data2 = list_add(list, allocate_int);

    *data = 1;
    *data2 = 2;
    cr_assert_eq(list_move_if(list, list2, list_int_gt, data2), 0);
    cr_assert_eq(list->size, 2);
    cr_assert_eq(list_size(list2), 0);
    list_destroy(list, destroy_int);
    list_destroy(list2, NULL);
}

Test(list_move_if, move_if_match)
{
    list_t *list = list_create();
    list_t *list2 = list_create();
    int *data = list_add(list, allocate_int);
    int *data2 = list_add(list, allocate_int);

    *data = 1;
    *data2 = 2;
    cr_assert_eq(list_move_if(list, list2, list_int_gt, data), 1);
    cr_assert_eq(list->size, 1);
    cr_assert_eq(list_size(list2), 1);
    cr_assert_eq(list_at(list2, 0), data2);
    list_destroy(list, NULL);
    list_destroy(list2, NULL);
}
