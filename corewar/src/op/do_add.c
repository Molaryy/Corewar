/*
** EPITECH PROJECT, 2023
** corewar/src/op/do_add.c
** File description:
** this will contain the add functions for the instruction
*/
#include "core.h"
#include <stdbool.h>

static bool handle_check(cursor_t *cursor)
{
    static bool check = false;

    if (!check) {
        cursor->cycles_to_wait = 10;
        check = true;
    }
    if (check && cursor->cycles_to_wait > 0) {
        cursor->cycles_to_wait--;
        return (false);
    }
    check = false;
    return (true);
}

static int get_bits(unsigned char *buffer)
{
    int res = 0;
    int byte_index;
    int bit_index;
    unsigned int bit;

    for (int i = 0; i < 8; i++) {
        byte_index = i / 8;
        bit_index = i % 8;
        bit = (buffer[byte_index] >> (7 - bit_index)) & 1;
        res = (res << 1) | bit;
    }
    return (res);
}

void do_add(champion_t *champion, cursor_t *cursor, vm_t *vm,
__attribute__((unused)) const op_t *op)
{
    int index;
    int reg1;
    int reg2;
    int reg3;
    int nb1;
    int nb2;

    if (!handle_check(cursor))
        return;
    index = (int)get_32uint(cursor->pc.bytes);
    reg1 = get_bits(vm->memory + index + 2);
    reg2 = get_bits(vm->memory + index + 3);
    reg3 = get_bits(vm->memory + index + 4);
    nb1 = (int)get_32uint(champion->registers[reg1].bytes);
    nb2 = (int)get_32uint(champion->registers[reg2].bytes);
    nb1 += nb2;
    set_32uint(nb1, champion->registers[reg3].bytes);
    set_32uint((index + 5) % MEM_SIZE, cursor->pc.bytes);
}
