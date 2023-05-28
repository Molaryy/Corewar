/*
** EPITECH PROJECT, 2023
** corewar/src/op/my_aff.c
** File description:
** aff
*/

#include "core.h"

void my_aff(UNUSED champion_t *champion, cursor_t *cursor, vm_t *vm,
    const op_t *op)
{
    int index = (int) get_32uint(cursor->pc.bytes);
    long long int arg;
    uint32_t tmp = {0};

    for (int i = 0; i < REG_SIZE; i++)
        tmp.bytes[i] = vm->memory[(index + i + 1) % MEM_SIZE];
    for (int i = 0; i < op->nbr_args; i++) {
        index += REG_SIZE;
        arg = get_32uint(tmp.bytes);
        my_printf("%c", arg % 256);
    }
    set_32uint(++index % MEM_SIZE, cursor->pc.bytes);
}
