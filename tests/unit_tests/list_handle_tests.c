/*
** EPITECH PROJECT, 2024
** myteams
** File description:
** list_handle_tests
*/

#include <criterion/criterion.h>
#include "test_utils.h"
#include "list.h"

Test(list_get, get_index_in_range)
{
    list_t *list = list_create();
    int *data_get = NULL;
    int *data = list_add(list, allocate_int);
    int *data2 = list_add(list, allocate_int);
    int *data3 = list_add(list, allocate_int);
    int *data4 = list_add(list, allocate_int);

    cr_assert_not_null(list);
    cr_assert_not_null(data);
    cr_assert_not_null(data2);
    *data = 1;
    *data2 = 2;
    *data3 = 3;
    *data4 = 4;
    data_get = list_iget(list, 2);
    cr_assert_not_null(data_get);
    cr_assert_eq(data_get, data3);
    list_destroy(list, destroy_int);
}

Test(list_get, get_index_out_of_range)
{
    list_t *list = list_create();
    int *data_get = NULL;
    int *data = list_add(list, allocate_int);
    int *data2 = list_add(list, allocate_int);
    int *data3 = list_add(list, allocate_int);
    int *data4 = list_add(list, allocate_int);

    cr_assert_not_null(list);
    cr_assert_not_null(data);
    cr_assert_not_null(data2);
    *data = 1;
    *data2 = 2;
    *data3 = 3;
    *data4 = 4;
    data_get = list_iget(list, 12);
    cr_assert_not_null(data_get);
    cr_assert_eq(data_get, data4);
    list_destroy(list, destroy_int);
}

Test(list_get, get_index_negative)
{
    list_t *list = list_create();
    int *data_get = NULL;
    int *data = list_add(list, allocate_int);
    int *data2 = list_add(list, allocate_int);
    int *data3 = list_add(list, allocate_int);
    int *data4 = list_add(list, allocate_int);

    cr_assert_not_null(list);
    cr_assert_not_null(data);
    cr_assert_not_null(data2);
    *data = 1;
    *data2 = 2;
    *data3 = 3;
    *data4 = 4;
    data_get = list_iget(list, -2);
    cr_assert_not_null(data_get);
    cr_assert_eq(data_get, data3);
    list_destroy(list, destroy_int);
}

Test(list_get, get_empty_list)
{
    list_t *list = list_create();
    int *data_get = NULL;

    cr_assert_not_null(list);
    data_get = list_iget(list, 0);
    cr_assert_null(data_get);
    list_destroy(list, destroy_int);
}

Test(list_get, get_first)
{
    list_t *list = list_create();
    int *data_get = NULL;
    int *data = list_add(list, allocate_int);
    int *data2 = list_add(list, allocate_int);
    int *data3 = list_add(list, allocate_int);

    cr_assert_not_null(list);
    cr_assert_not_null(data);
    cr_assert_not_null(data2);
    *data = 1;
    *data2 = 2;
    *data3 = 3;
    data_get = list_iget(list, 0);
    cr_assert_not_null(data_get);
    cr_assert_eq(data_get, data);
    list_destroy(list, destroy_int);
}

Test(list_get, get_last)
{
    list_t *list = list_create();
    int *data_get = NULL;
    int *data = list_add(list, allocate_int);
    int *data2 = list_add(list, allocate_int);
    int *data3 = list_add(list, allocate_int);

    cr_assert_not_null(list);
    cr_assert_not_null(data);
    cr_assert_not_null(data2);
    *data = 1;
    *data2 = 2;
    *data3 = 3;
    data_get = list_iget(list, 2);
    cr_assert_not_null(data_get);
    cr_assert_eq(data_get, data3);
    list_destroy(list, destroy_int);
}
