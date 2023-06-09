/*
** EPITECH PROJECT, 2023
** corewar/src/op/my_aff.c
** File description:
** aff
*/

#include "core.h"

void my_aff(UNUSED champion_t *champion, cursor_t *cursor, vm_t *vm,
    UNUSED const op_t *op)
{
    int index = (int) get_32uint(cursor->pc.bytes);
    int reg = (int) vm->memory[(++index) % MEM_SIZE];

    disp_32uint_h(champion->registers[reg - 1].bytes);
    int value = (int) get_32uint(champion->registers[reg - 1].bytes);
    my_putchar((unsigned char)(value % 256));
    set_32uint(++index % MEM_SIZE, cursor->pc.bytes);
}
