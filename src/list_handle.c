/*
** EPITECH PROJECT, 2024
** myteams
** File description:
** list_handle
*/

#include <stdlib.h>
#include "linked.h"

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

void *list_at(list_t *list, int index)
{
    int size = 0;

    size = list_size(list);
    if (size == 0)
        return NULL;
    if (index < 0)
        return get_from_back(list->tail, abs(index) - 1);
    return get_from_front(list->head, index >= size ? size - 1 : index);
}

bool list_move(list_t *from, int at, list_t *to)
{
    void *data = NULL;

    if (!from || !to)
        return false;
    data = list_at(from, at);
    if (!data)
        return false;
    if (!list_add_ptr(to, data))
        return false;
    return list_pop(from, at);
}

bool list_apply(list_t *list, applicator_t apply, void *accumulator)
{
    if (!list || !apply || !accumulator)
        return false;
    for (node_t *i = list->head; i; i = i->next) {
        apply(accumulator, i->data);
    }
    return true;
}

bool list_map(list_t *list, callback_t map)
{
    if (!list || !map)
        return false;
    for (node_t *i = list->head; i; i = i->next) {
        map(i->data);
    }
    return true;
}
