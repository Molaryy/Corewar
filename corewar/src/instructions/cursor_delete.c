/*
** EPITECH PROJECT, 2023
** instructions
** File description:
** cursor_delete
*/
#include "cursors.h"
#include <stdlib.h>

void cursor_delete(cursor_t *list)
{
    if (!list)
        return;
    while (list->first)
        cursor_remove(list);
    free(list);
}
