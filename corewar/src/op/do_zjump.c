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

static int bytes_to_int(const unsigned char buffer[4])
{
    int value = 0;

    value |= buffer[0] << 24;
    value |= buffer[1] << 16;
    value |= buffer[2] << 8;
    value |= buffer[3];
    return (value);
}

static int get_value(unsigned char *mem, int adress, int size)
{
    int value = 0;

    for (int i = 0; i < size; i++) {
        value = (value << 8) | mem[(adress + i)] % MEM_SIZE;
    }
    return (value);
}

void do_zjmp(champion_t *champion, cursor_t *cursor, vm_t *vm,
__attribute__((unused)) const op_t *op)
{
    int index = (int)get_32uint(cursor->pc.bytes);
    int param = 0;
    int value = 0;

    if (!handle_check(cursor))
        return;
    param = get_value(vm->memory, index + 1, DIR_SIZE);
    value = bytes_to_int(cursor->pc.bytes);
    if (cursor->carry) {
        value += param;
        value %= MEM_SIZE;
        int_to_bytes(value, cursor->pc.bytes);
        cursor->carry = 1;
    } else {
        value += 1;
        if (value >= MEM_SIZE)
            value = 0;
        int_to_bytes(value, cursor->pc.bytes);
    }
    my_printf("value = %d\n", value);
}
