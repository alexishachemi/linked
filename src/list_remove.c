/*
** EPITECH PROJECT, 2024
** myteams
** File description:
** list_remove
*/

#include <stdlib.h>
#include "list.h"

static void pop_from_front(list_t *list, size_t count, void **data)
{
    node_t *node = list ? list->head : NULL;
    node_t *prev = node ? node->prev : NULL;
    node_t *next = node ? node->next : NULL;

    while (count > 0 && node) {
        prev = node;
        node = node->next;
        next = node ? node->next : NULL;
        count--;
    }
    node_isolate(node);
    if (node) {
        *data = node->data;
        node_destroy(node, NULL);
        if (!prev)
            list_set_head(list, next);
        if (!next)
            list_set_tail(list, prev);
    }
}

static void pop_from_back(list_t *list, size_t count, void **data)
{
    node_t *node = list ? list->tail : NULL;
    node_t *prev = node ? node->prev : NULL;
    node_t *next = node ? node->next : NULL;

    while (count > 0 && node) {
        next = node;
        node = node->prev;
        prev = node ? node->prev : NULL;
        count--;
    }
    node_isolate(node);
    if (node) {
        *data = node->data;
        node_destroy(node, NULL);
        if (!prev)
            list_set_head(list, next);
        if (!next)
            list_set_tail(list, prev);
    }
}

void *list_ipop(list_t *list, int index)
{
    int size = 0;
    node_t *node = NULL;
    void *data = NULL;

    size = list_size(list);
    if (size == 0)
        return NULL;
    if (size == 1) {
        node = list->head;
        data = node->data;
        list->head = NULL;
        list->tail = NULL;
        node_destroy(node, NULL);
        return data;
    }
    if (index < 0)
        pop_from_back(list, abs(index) - 1, &data);
    else
        pop_from_front(list, index >= size ? size - 1 : index, &data);
    return data;
}

bool list_iremove(list_t *list, callback_t destroy, int index)
{
    node_t *node = NULL;

    node = list_ipop(list, index);
    if (node) {
        destroy(node);
        return true;
    }
    return false;
}

bool list_iremove_free(list_t *list, int index)
{
    return list_iremove(list, free, index);
}