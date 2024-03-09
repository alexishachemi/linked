/*
** EPITECH PROJECT, 2024
** liblinked
** File description:
** list_utils
*/

#include <stddef.h>
#include "list.h"

void isolate_node(node_t *node)
{
    if (!node)
        return;
    if (node->prev)
        node->prev->next = node->next;
    if (node->next)
        node->next->prev = node->prev;
    if (node->list) {
        if (node->list->head == node)
            node->list->head = node->next ? node->next : node->prev;
        if (node->list->tail == node)
            node->list->tail = node->prev ? node->prev : node->next;
    }
    node->list = NULL;
    node->prev = NULL;
    node->next = NULL;
}
