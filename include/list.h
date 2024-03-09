/*
** EPITECH PROJECT, 2024
** liblinked
** File description:
** list
*/

#ifndef LIST_H_
    #define LIST_H_
    #include <stdbool.h>

typedef struct list_s list_t;
typedef struct node_s node_t;

struct list_s {
    node_t *head;
    node_t *tail;
};

struct node_s {
    void *data;
    list_t *list;
    node_t *prev;
    node_t *next;
};

typedef void *(*allocator_t)();
typedef bool (*comparator_t)(void *, void *);
typedef void (*callback_t)(void *);

// creating

node_t *alloc_node(allocator_t allocate);
list_t *alloc_list(void);

// destructing

void free_node(node_t *node, callback_t destroy);
void free_nodes(node_t *node, callback_t destroy);
void clear_list(list_t *list, callback_t destroy);
void free_list(list_t *list, callback_t destroy);

// adding

void *list_add(list_t *list, allocator_t allocate);
void *list_iinsert(list_t *list, allocator_t allocate, int index);
void *list_cinsert(list_t *list, allocator_t allocate,
    comparator_t compare, void *compared);

// removing

void *list_ipop(list_t *list, int index);
void *list_cpop(list_t *list, comparator_t compare, void *compared);
bool list_iremove(list_t *list, callback_t destroy, int index);
bool list_cremove(list_t *list, callback_t destroy,
    comparator_t compare, void *compared);

// handling

void *list_iget(list_t *list, int index);
void *list_cget(list_t *list, comparator_t compare, void *compared);

// utilities

void isolate_node(node_t *node);

#endif /* !LIST_H_ */
