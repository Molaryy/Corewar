/*
** EPITECH PROJECT, 2023
** corewar/src/cursor/init.c
** File description:
** init functions for the cursors inside the corewar project
*/

#include "core.h"

cursor_t *cursor_init(info_corewar_t *info, int index)
{
    cursor_t *cursor = malloc(sizeof(cursor_t));

    if (!cursor)
        stop(info, 84);
    cursor->carry = TRUE;
    set_32uint(index, cursor->pc.bytes);
    cursor->cycles_left = 0;
    cursor->next = NULL;
    cursor->prev = NULL;
    return cursor;
}