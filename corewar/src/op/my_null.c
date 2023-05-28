/*
** EPITECH PROJECT, 2023
** corewar/src/op/my_null.c
** File description:
** null code so char 0 for unmapped memory
*/

#include "core.h"

void my_null(UNUSED champion_t *champion, UNUSED cursor_t *cursor,
    UNUSED vm_t *vm, UNUSED const op_t *op)
{
    set_32uint(((int) get_32uint(cursor->pc.bytes) + 1) % MEM_SIZE,
        cursor->pc.bytes);
}
