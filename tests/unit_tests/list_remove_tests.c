/*
** EPITECH PROJECT, 2024
** myteams
** File description:
** list_remove_tests
*/

#include <criterion/criterion.h>
#include "test_utils.h"
#include "list.h"

Test(list_remove, remove_index_in_range)
{
    list_t *list = list_create();
    int *data = list_add(list, allocate_int);
    int *data2 = list_add(list, allocate_int);
    int *data3 = list_add(list, allocate_int);
    int *data4 = list_add(list, allocate_int);
    int *data_removed = NULL;

    cr_assert_not_null(list);
    cr_assert_not_null(data);
    cr_assert_not_null(data2);
    cr_assert_not_null(data3);
    cr_assert_not_null(data4);
    *data = 1;
    *data2 = 2;
    *data3 = 3;
    *data4 = 4;
    cr_assert_eq(list_size(list), 4);
    data_removed = list_ipop(list, 2);
    cr_assert_not_null(data_removed);
    cr_assert_eq(data_removed, data3);
    cr_assert_eq(list_size(list), 3);
    cr_assert_eq(list->head->data, data);
    cr_assert_eq(list->head->next->data, data2);
    cr_assert_eq(list->head->next->next->data, data4);
    cr_assert_null(list->head->next->next->next);
    list_destroy(list, destroy_int);
    destroy_int(data_removed);
}

Test(list_remove, remove_index_out_of_range)
{
    list_t *list = list_create();
    int *data = list_add(list, allocate_int);
    int *data2 = list_add(list, allocate_int);
    int *data3 = list_add(list, allocate_int);
    int *data4 = list_add(list, allocate_int);
    int *data_removed = NULL;

    cr_assert_not_null(list);
    cr_assert_not_null(data);
    cr_assert_not_null(data2);
    cr_assert_not_null(data3);
    cr_assert_not_null(data4);
    *data = 1;
    *data2 = 2;
    *data3 = 3;
    *data4 = 4;
    cr_assert_eq(list_size(list), 4);
    data_removed = list_ipop(list, 12);
    cr_assert_eq(list_size(list), 3);
    cr_assert_eq(data_removed, data4);
    cr_assert_eq(list->head->data, data);
    cr_assert_eq(list->head->next->data, data2);
    cr_assert_eq(list->head->next->next->data, data3);
    cr_assert_null(list->head->next->next->next);
    list_destroy(list, destroy_int);
    destroy_int(data_removed);
}

Test(list_remove, remove_index_zero)
{
    list_t *list = list_create();
    int *data = list_add(list, allocate_int);
    int *data2 = list_add(list, allocate_int);
    int *data3 = list_add(list, allocate_int);
    int *data4 = list_add(list, allocate_int);
    int *data_removed = NULL;

    cr_assert_not_null(list);
    cr_assert_not_null(data);
    cr_assert_not_null(data2);
    cr_assert_not_null(data3);
    cr_assert_not_null(data4);
    *data = 1;
    *data2 = 2;
    *data3 = 3;
    *data4 = 4;
    cr_assert_eq(list_size(list), 4);
    data_removed = list_ipop(list, 0);
    cr_assert_eq(list_size(list), 3);
    cr_assert_eq(data_removed, data);
    cr_assert_eq(list->head->data, data2);
    cr_assert_eq(list->head->next->data, data3);
    cr_assert_eq(list->head->next->next->data, data4);
    cr_assert_null(list->head->next->next->next);
    list_destroy(list, destroy_int);
    destroy_int(data_removed);
}

Test(list_remove, remove_index_last)
{
    list_t *list = list_create();
    int *data = list_add(list, allocate_int);
    int *data2 = list_add(list, allocate_int);
    int *data3 = list_add(list, allocate_int);
    int *data4 = list_add(list, allocate_int);
    int *data_removed = NULL;

    cr_assert_not_null(list);
    cr_assert_not_null(data);
    cr_assert_not_null(data2);
    cr_assert_not_null(data3);
    cr_assert_not_null(data4);
    *data = 1;
    *data2 = 2;
    *data3 = 3;
    *data4 = 4;
    cr_assert_eq(list_size(list), 4);
    data_removed = list_ipop(list, 3);
    cr_assert_eq(list_size(list), 3);
    cr_assert_eq(data_removed, data4);
    cr_assert_eq(list->head->data, data);
    cr_assert_eq(list->head->next->data, data2);
    cr_assert_eq(list->head->next->next->data, data3);
    cr_assert_null(list->head->next->next->next);
    list_destroy(list, destroy_int);
    destroy_int(data_removed);
}

Test(list_remove, remove_index_negative)
{
    list_t *list = list_create();
    int *data = list_add(list, allocate_int);
    int *data2 = list_add(list, allocate_int);
    int *data3 = list_add(list, allocate_int);
    int *data4 = list_add(list, allocate_int);
    int *data_removed = NULL;

    cr_assert_not_null(list);
    cr_assert_not_null(data);
    cr_assert_not_null(data2);
    cr_assert_not_null(data3);
    cr_assert_not_null(data4);
    *data = 1;
    *data2 = 2;
    *data3 = 3;
    *data4 = 4;
    cr_assert_eq(list_size(list), 4);
    data_removed = list_ipop(list, -3);
    cr_assert_eq(list_size(list), 3);
    cr_assert_not_null(data_removed);
    cr_assert_eq(data_removed, data2);
    cr_assert_eq(list->head->data, data);
    cr_assert_eq(list->head->next->data, data3);
    cr_assert_eq(list->head->next->next->data, data4);
    cr_assert_null(list->head->next->next->next);
    list_destroy(list, destroy_int);
    destroy_int(data_removed);
}
