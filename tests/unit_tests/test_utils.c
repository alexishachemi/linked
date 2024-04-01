/*
** EPITECH PROJECT, 2024
** liblinked
** File description:
** test_utils
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "test_utils.h"

void destroy_int(void *data)
{
    free(data);
}

void *allocate_int(void)
{
    return malloc(sizeof(int));
}

void print_int(void *data)
{
    if (!data)
        return;
    printf("%d\n", *(int*)data);
}

bool int_eq(void *data, void *data2)
{
    if (!data || !data2)
        return false;
    return *(int*)data == *(int*)data2;
}

bool int_gt(void *data, void *data2)
{
    if (!data || !data2)
        return false;
    return *(int*)data > *(int*)data2;
}

bool int_lt(void *data, void *data2)
{
    if (!data || !data2)
        return false;
    return *(int*)data < *(int*)data2;
}
