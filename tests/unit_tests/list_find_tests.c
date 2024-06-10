/*
** EPITECH PROJECT, 2024
** linked
** File description:
** list_find_tests
*/

#include <criterion/criterion.h>
#include "linked_dev.h"
#include "test_utils.h"

Test(list_find, find_success)
{
    list_t *list = list_create();
    int *data = list_add(list, allocate_int);
    int *data2 = list_add(list, allocate_int);
    int *data3 = list_add(list, allocate_int);
    int *data4 = list_add(list, allocate_int);
    int index = 0;

    cr_assert_not_null(list);
    cr_assert_not_null(data);
    cr_assert_not_null(data2);
    cr_assert_not_null(data3);
    cr_assert_not_null(data4);
    *data = 1;
    *data2 = 2;
    *data3 = 3;
    *data4 = 4;
    index = list_find(list, list_int_eq, data3);
    cr_assert_eq(index, 2);
    list_destroy(list, destroy_int);
}

Test(list_find, find_failure)
{
    list_t *list = list_create();
    int *data = list_add(list, allocate_int);
    int *data2 = list_add(list, allocate_int);
    int *data3 = list_add(list, allocate_int);
    int *data4 = list_add(list, allocate_int);
    int to_find = 5;
    int index = 0;

    cr_assert_not_null(list);
    cr_assert_not_null(data);
    cr_assert_not_null(data2);
    cr_assert_not_null(data3);
    cr_assert_not_null(data4);
    *data = 1;
    *data2 = 2;
    *data3 = 3;
    *data4 = 4;
    index = list_find(list, list_int_eq, &to_find);
    cr_assert_eq(index, -1);
    list_destroy(list, destroy_int);
}

Test(list_find, find_null_list)
{
    int index = 0;

    index = list_find(NULL, list_int_eq, NULL);
    cr_assert_eq(index, -1);
}

Test(list_find, find_null_cmp)
{
    list_t *list = list_create();
    int *data = list_add(list, allocate_int);
    int index = 0;

    cr_assert_not_null(list);
    cr_assert_not_null(data);
    *data = 1;
    index = list_find(list, NULL, data);
    cr_assert_eq(index, -1);
    list_destroy(list, destroy_int);
}

Test(list_find, find_null_data)
{
    list_t *list = list_create();
    int index = 0;

    cr_assert_not_null(list);
    index = list_find(list, list_int_eq, NULL);
    cr_assert_eq(index, -1);
    list_destroy(list, destroy_int);
}

Test(list_find_ptr, find_ptr_success)
{
    list_t *list = list_create();
    int *data = list_add(list, allocate_int);
    int *data2 = list_add(list, allocate_int);
    int *data3 = list_add(list, allocate_int);
    int *data4 = list_add(list, allocate_int);
    int index = 0;

    cr_assert_not_null(list);
    cr_assert_not_null(data);
    cr_assert_not_null(data2);
    cr_assert_not_null(data3);
    cr_assert_not_null(data4);
    *data = 1;
    *data2 = 2;
    *data3 = 3;
    *data4 = 4;
    index = list_find_ptr(list, data3);
    cr_assert_eq(index, 2);
    list_destroy(list, destroy_int);
}

Test(list_find_ptr, find_ptr_failure)
{
    list_t *list = list_create();
    int *data = list_add(list, allocate_int);
    int *data2 = list_add(list, allocate_int);
    int *data3 = list_add(list, allocate_int);
    int *data4 = list_add(list, allocate_int);
    int to_find = 5;
    int index = 0;

    cr_assert_not_null(list);
    cr_assert_not_null(data);
    cr_assert_not_null(data2);
    cr_assert_not_null(data3);
    cr_assert_not_null(data4);
    *data = 1;
    *data2 = 2;
    *data3 = 3;
    *data4 = 4;
    index = list_find_ptr(list, &to_find);
    cr_assert_eq(index, -1);
    list_destroy(list, destroy_int);
}

Test(list_find_ptr, find_ptr_null_list)
{
    int index = 0;

    index = list_find_ptr(NULL, NULL);
    cr_assert_eq(index, -1);
}

Test(list_find_ptr, find_ptr_null_data)
{
    list_t *list = list_create();
    int index = 0;

    cr_assert_not_null(list);
    index = list_find_ptr(list, NULL);
    cr_assert_eq(index, -1);
    list_destroy(list, destroy_int);
}
