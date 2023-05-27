/*
** EPITECH PROJECT, 2023
** instructions
** File description:
** cursor_create
*/
#include "cursors.h"
#include <stdlib.h>

cursor_t *cursor_create(void)
{
    cursor_t *list = malloc(sizeof(*list));

    if (!list)
        return (NULL);
    list->first = NULL;
    list->end = NULL;
    list->size = 0;
    return (list);
}
