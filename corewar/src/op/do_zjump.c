/*
** EPITECH PROJECT, 2023
** corewar/src/op/do_zjmp.c
** File description:
** this will contain the zjmp functions for the instruction
*/
#include "core.h"
#include <stdbool.h>

static bool handle_check(cursor_t *cursor)
{
    static bool check = false;

    if (!check) {
        cursor->cycles_to_wait = 20;
        check = true;
    }
    if (check && cursor->cycles_to_wait > 0) {
        cursor->cycles_to_wait--;
        return (false);
    }
    check = false;
    return (true);
}

void do_zjmp(champion_t *champion, cursor_t *cursor, vm_t *vm,
__attribute__((unused)) const op_t *op)
{
    int index = (int)get_32uint(cursor->pc.bytes);
    int new_adress = get_value(vm->memory, index + 1, DIR_SIZE);

    if (!handle_check(cursor))
        return;
    if (cursor->carry) {
        cursor->pc.bytes = new_adress % MEM_SIZE;
    } else {

    }
}
