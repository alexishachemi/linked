/*
** EPITECH PROJECT, 2024
** liblinked
** File description:
** list_destroy
*/

#include <stdlib.h>
#include "list.h"

void free_node(node_t *node, callback_t destroy)
{
    if (!node)
        return;
    if (node->data && destroy)
        destroy(node->data);
    free(node);
}

void free_nodes(node_t *node, callback_t destroy)
{
    node_t *prev = NULL;

    if (!node)
        return;
    while (node->prev)
        node = node->prev;
    while (node) {
        prev = node;
        node = node->next;
        isolate_node(prev);
        free_node(prev, destroy);
    }
}

void clear_list(list_t *list, callback_t destroy)
{
    if (!list)
        return;
    free_nodes(list->head, destroy);
    list->head = NULL;
    list->tail = NULL;
}

void free_list(list_t *list, callback_t destroy)
{
    if (!list)
        return;
    clear_list(list, destroy);
    free(list);
}
