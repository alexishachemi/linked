/*
** EPITECH PROJECT, 2024
** liblinked
** File description:
** list
*/

#ifndef LIST_H_
    #define LIST_H_
    #include <stdbool.h>
    #include <unistd.h>

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
typedef void (*callback_t)(void *);
typedef void (*applicator_t)(void *, void *);

// creating

node_t *node_create(allocator_t allocate);
list_t *list_create(void);
void list_init(list_t *list);

// destructing

void node_destroy(node_t *node, callback_t destroy);
void node_destroy_all(node_t *node, callback_t destroy);
void list_clear(list_t *list, callback_t destroy);
void list_destroy(list_t *list, callback_t destroy);
void list_clear_free(list_t *list);
void list_destroy_free(list_t *list);

// adding

void *list_add(list_t *list, allocator_t allocate);
void *list_add_ptr(list_t *list, void *ptr);
node_t *list_add_node(list_t *list, allocator_t allocate);
void *list_iinsert(list_t *list, allocator_t allocate, int index);

// removing

void *list_ipop(list_t *list, int index);
bool list_iremove(list_t *list, callback_t destroy, int index);
bool list_iremove_free(list_t *list, int index);

// handling

void *list_at(list_t *list, int index);
bool list_move(list_t *from, int at, list_t *to);
bool list_apply(list_t *list, applicator_t apply, void *accumulator);
bool list_map(list_t *list, callback_t map);
// utilities

void node_isolate(node_t *node);
void list_print(list_t *list, callback_t print);
void node_link(node_t *node, ...);

size_t list_size(list_t *list);
bool list_empty(list_t *list);

void list_set_head(list_t *list, node_t *node);
void list_set_tail(list_t *list, node_t *node);

#endif /* !LIST_H_ */
