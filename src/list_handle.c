/*
** EPITECH PROJECT, 2024
** myteams
** File description:
** list_handle
*/

#include <stdlib.h>
#include "list.h"

static void *get_from_front(node_t *node, size_t count)
{
    while (count > 0 && node) {
        node = node->next;
        count--;
    }
    if (node)
        return node->data;
    return NULL;
}

static void *get_from_back(node_t *node, size_t count)
{
    while (count > 0 && node) {
        node = node->prev;
        count--;
    }
    if (node)
        return node->data;
    return NULL;
}

void *list_iget(list_t *list, int index)
{
    int size = 0;

    size = list_size(list);
    if (size == 0)
        return NULL;
    if (index < 0)
        return get_from_back(list->tail, abs(index) - 1);
    return get_from_front(list->head, index >= size ? size - 1 : index);
}