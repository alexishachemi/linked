/*
** EPITECH PROJECT, 2024
** liblinked
** File description:
** list_create
*/

#include <stdlib.h>
#include "list.h"

node_t *node_create(allocator_t allocate)
{
    node_t *node = NULL;

    node = malloc(sizeof(node_t));
    if (!node)
        return NULL;
    node->data = allocate ? allocate() : NULL;
    if (allocate && !node->data) {
        free(node);
        return NULL;
    }
    node->list = NULL;
    node->prev = NULL;
    node->next = NULL;
    return node;
}

list_t *list_create(void)
{
    list_t *list = NULL;

    list = malloc(sizeof(list_t));
    if (!list)
        return NULL;
    list->head = NULL;
    list->tail = NULL;
    return list;
}
