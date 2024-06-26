/*
** EPITECH PROJECT, 2024
** linked
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

void sum_int(void *acc, void *data)
{
    int *acc_int = (int *)acc;
    int *data_int = (int *)data;

    if (!acc || !data)
        return;
    *acc_int += *data_int;
}

void inc_int(void *data)
{
    if (!data)
        return;
    (*(int*)data)++;
}
