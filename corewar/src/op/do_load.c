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

bool handle_check(cursor_t *cursor)
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

int get_value_param(vm_t *vm, int *idx, int index, int *register_index)
{
    int param1;
    int param2;
    int type_param = (vm->memory[index + 1] >> 6) & 0x03;
    int adress;

    if (type_param == 2) {
        param1 = get_value(vm->memory, index + 2, IND_SIZE);
        param2 = get_value(vm->memory, index + 2 + IND_SIZE, 4);
        (*idx) = IND_SIZE;
        (*register_index) = (param2 >> 8) & 0x07;
        return param1;
    } else if (type_param == 3) {
        param1 = get_value(vm->memory, index + 2, DIR_SIZE);
        param2 = get_value(vm->memory, index + 2 + DIR_SIZE, 4);
        adress = (index + param1) % MEM_SIZE;
        (*idx) = DIR_SIZE;
        (*register_index) = (param2 >> 8) & 0x07;
        return (get_value(vm->memory, adress, DIR_SIZE));
    }
    return (0);
}

void do_load(champion_t *champion, cursor_t *cursor, vm_t *vm,
__attribute__((unused)) const op_t *op)
{
    int index = (int)get_32uint(cursor->pc.bytes);
    int type_param;
    int register_index;
    int value;
    int idx;

    if (!handle_check(cursor))
        return;
    type_param = (vm->memory[index + 1] >> 6) & 0x03;
    if (type_param != 2 && type_param != 3) {
        cursor->carry = 0;
        return;
    }
    value = get_value_param(vm, &idx, index, &register_index);
    int_to_bytes(value, champion->registers[register_index - 1].bytes);
    set_32uint((index + idx + 4 + 1) % MEM_SIZE, cursor->pc.bytes);
}
