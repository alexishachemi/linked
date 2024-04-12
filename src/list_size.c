/*
** EPITECH PROJECT, 2024
** myteams
** File description:
** list_size
*/

#include "linked.h"

size_t list_size(list_t *list)
{
    size_t size = 0;

    if (!list || !list->head)
        return 0;
    for (node_t *node = list->head; node; node = node->next) {
        size++;
    }
    return size;
}

bool list_empty(list_t *list)
{
    return !(list && list->head);
}
