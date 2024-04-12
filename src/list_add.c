/*
** EPITECH PROJECT, 2024
** liblinked
** File description:
** list_add
*/
#include <stdlib.h>
#include <stddef.h>
#include "linked.h"

void *list_add(list_t *list, allocator_t allocate)
{
    node_t *node = NULL;

    if (!list)
        return NULL;
    node = node_create(allocate);
    if (!node)
        return NULL;
    node_link(list->tail, node, NULL);
    list->tail = node;
    if (!list->head)
        list->head = node;
    node->list = list;
    return node->data;
}

static void insert_from_back(node_t *node, node_t *new, int count)
{
    node_t *next = NULL;

    while (count > 0 && node) {
        next = node;
        node = node->prev;
        count--;
    }
    if (node)
        node_link(node, new, next, NULL);
    else
        node_link(new, next, NULL);
}

static void insert_from_front(node_t *node, node_t *new, int count)
{
    node_t *prev = NULL;

    while (count > 0 && node) {
        prev = node;
        node = node->next;
        count--;
    }
    if (node)
        node_link(prev, new, node, NULL);
    else
        node_link(prev, new, NULL);
}

static void connect_to_list(list_t *list, node_t *node)
{
    if (!node->prev)
        list_set_head(list, node);
    if (!node->next)
        list_set_tail(list, node);
    node->list = list;
}

void *list_iinsert(list_t *list, allocator_t allocate, int index)
{
    node_t *node = NULL;

    if (!list)
        return NULL;
    node = node_create(allocate);
    if (!node)
        return NULL;
    if (index < 0)
        insert_from_back(list->tail, node, abs(index) - 1);
    else
        insert_from_front(list->head, node, index);
    connect_to_list(list, node);
    return node->data;
}
