/*
** EPITECH PROJECT, 2024
** liblinked
** File description:
** list_destroy_tests
*/

#include <criterion/criterion.h>
#include "list.h"

static void destroy_int(void *data)
{
    free(data);
}

static void *allocate_int(void)
{
    return malloc(sizeof(int));
}

Test(free_node, free_node_no_destroy)
{
    node_t *node = alloc_node(NULL);

    free_node(node, NULL);
    cr_assert(1);
}


Test(free_node, free_node_with_destroy)
{
    node_t *node = alloc_node(allocate_int);

    free_node(node, destroy_int);
    cr_assert(1);
}

Test(free_node, free_node_null)
{
    free_node(NULL, destroy_int);
    cr_assert(1);
}

Test(free_nodes, free_nodes_no_destroy)
{
    node_t *node = alloc_node(NULL);

    free_nodes(node, NULL);
    cr_assert(1);
}

Test(free_nodes, free_nodes_with_destroy)
{
    node_t *node = alloc_node(allocate_int);

    free_nodes(node, destroy_int);
    cr_assert(1);
}

Test(free_nodes, free_nodes_null)
{
    free_nodes(NULL, destroy_int);
    cr_assert(1);
}

Test(clear_list, clear_list_no_destroy)
{
    list_t list = {NULL, NULL};
    node_t *node = alloc_node(NULL);

    list.head = node;
    list.tail = node;
    clear_list(&list, NULL);
    cr_assert_null(list.head);
    cr_assert_null(list.tail);
}

Test(clear_list, clear_list_with_destroy)
{
    list_t list = {NULL, NULL};
    node_t *node = alloc_node(allocate_int);

    list.head = node;
    list.tail = node;
    clear_list(&list, destroy_int);
    cr_assert_null(list.head);
    cr_assert_null(list.tail);
}

Test(free_list, free_list_no_destroy)
{
    list_t *list = alloc_list();

    free_list(list, NULL);
    cr_assert(1);
}

Test(free_list, free_list_with_destroy)
{
    list_t *list = alloc_list();

    free_list(list, destroy_int);
    cr_assert(1);
}

Test(free_list, free_list_null)
{
    free_list(NULL, destroy_int);
    cr_assert(1);
}
