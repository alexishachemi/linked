/*
** EPITECH PROJECT, 2024
** liblinked
** File description:
** list_create_tests
*/

#include <criterion/criterion.h>
#include <list.h>

Test(list_create, list_alloc)
{
    list_t *list = alloc_list();

    cr_assert_not_null(list);
    cr_assert_null(list->head);
    cr_assert_null(list->tail);
    free(list);
}

Test(alloc_node, node_alloc_no_allocator)
{
    node_t *node = alloc_node(NULL);

    cr_assert_not_null(node);
    cr_assert_null(node->data);
    cr_assert_null(node->list);
    cr_assert_null(node->prev);
    cr_assert_null(node->next);
    free(node);
}

void *allocate_int(void)
{
    return malloc(sizeof(int));
}

Test(alloc_node, alloc_node_with_allocator)
{
    node_t *node = alloc_node(allocate_int);
    int *data = NULL;

    cr_assert_not_null(node);
    data = node->data;
    cr_assert_not_null(data);
    cr_assert_null(node->list);
    cr_assert_null(node->prev);
    cr_assert_null(node->next);
    free(data);
    free(node);
}
