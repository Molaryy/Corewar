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
    my_printf("my_aff\n");
    int index = (int) get_32uint(cursor->pc.bytes);
    int arg_type = (int) vm->memory[(++index) % MEM_SIZE];
    int reg = (int) vm->memory[(++index) % MEM_SIZE];

    my_printf("register = %d\n", reg);
    disp_32uint_h(champion->registers[reg - 1].bytes);
    int value = (int) get_32uint(champion->registers[reg - 1].bytes);
    my_printf("value = %d\n", value);
    my_putchar((unsigned char)(value % 256));
    set_32uint(++index % MEM_SIZE, cursor->pc.bytes);
    my_printf("pc = %d\n", (int) get_32uint(cursor->pc.bytes));
}
