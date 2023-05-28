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

static int get_adress(unsigned char *buffer)
{
    int adress;
    int byte_index;
    int bit_index;
    unsigned int bit;

    for (int i = 0; i < 8; i++) {
        byte_index = i / 8;
        bit_index = i % 8;
        bit = (buffer[byte_index] >> (7 - bit_index)) & 1;
        adress = (adress << 1) | bit;
    }
    return (adress);
}

void do_zjmp(champion_t *champion, cursor_t *cursor, vm_t *vm,
__attribute__((unused)) const op_t *op)
{
    int index;
    int adress;

    if (!handle_check(cursor))
        return;
    index = (int)get_32uint(cursor->pc.bytes);
    adress = get_adress(vm->memory + index + 2);
    if (cursor->carry == 0) {
        adress += index;
        set_32uint(adress, cursor->pc.bytes);
        return;
    } else {
        index += 1;
        if (index >= MEM_SIZE)
            index = 0;
        set_32uint(index, cursor->pc.bytes);
    }
}