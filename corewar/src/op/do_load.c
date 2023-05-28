/*
** EPITECH PROJECT, 2023
** corewar/src/op/do_load.c
** File description:
** this will contain the load functions for the instruction
*/
#include "core.h"
#include <stdbool.h>

static int get_value(unsigned char *mem, int adress, int size)
{
    int value = 0;

    for (int i = 0; i < size; i++) {
        value = (value << 8) | mem[(adress + i)] % MEM_SIZE;
    }
    return (value);
}

void int_to_bytes(int value, unsigned char buffer[4])
{
    buffer[0] = (value >> 24) & 0xFF;
    buffer[1] = (value >> 16) & 0xFF;
    buffer[2] = (value >> 8) & 0xFF;
    buffer[3] = value & 0xFF;
}

static bool handle_check(cursor_t *cursor)
{
    static bool check = false;

    if (!check) {
        cursor->cycles_to_wait = 5;
        check = true;
    }
    if (check && cursor->cycles_to_wait > 0) {
        cursor->cycles_to_wait--;
        return (false);
    }
    check = false;
    return (true);
}

int get_value_param(vm_t *vm, int *index, int *register_index)
{
    int param1;
    unsigned char *arg_type = get_sti_arg_type(vm, ++(*index), 2);

    (*index)++;
    for (int i = 0; i < 2; i++) {
        if (arg_type[i] == REG_SIZE)
            *register_index = vm->memory[*index];
        if (arg_type[i] == DIR_SIZE)
            param1 = get_32uint(&vm->memory[*index]);
        if (arg_type[i] == IND_SIZE)
            param1 = get_16int(&vm->memory[*index]);
        *index += arg_type[i];
    }
    return param1;
}

void do_load(champion_t *champion, cursor_t *cursor, vm_t *vm,
    __attribute__((unused)) const op_t *op)
{
    int index = (int)get_32uint(cursor->pc.bytes);
    int type_param;
    int register_index;
    int value;

    if (!handle_check(cursor))
        return;
    type_param = (vm->memory[index + 1] >> 6) & 0x03;
    if (type_param != 2 && type_param != 3) {
        cursor->carry = 0;
        return;
    }
    value = get_value_param(vm, &index, &register_index);
    set_32uint(value, champion->registers[register_index - 1].bytes);
    disp_32uint_h(champion->registers[register_index - 1].bytes);
    set_32uint(index % MEM_SIZE, cursor->pc.bytes);
}
