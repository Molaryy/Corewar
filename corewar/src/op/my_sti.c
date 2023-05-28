/*
** EPITECH PROJECT, 2023
** corewar/src/op/my_sti.c
** File description:
** sti
*/

#include "core.h"

void get_sti_arg_type_cut(unsigned char *arg_type, int size)
{
    for (int i = 0; i < size; i++) {
        switch (arg_type[i]) {
            case 0x01:
                arg_type[i] = REG_SIZE;
                break;
            case 0x02:
                arg_type[i] = DIR_SIZE;
                break;
            case 0x03:
                arg_type[i] = IND_SIZE;
                break;
            default:
                break;
        }
    }
}

unsigned char *get_sti_arg_type(vm_t *vm, int index, int size)
{
    unsigned char *arg_type = malloc(sizeof(unsigned char) * size);
    unsigned char mv = 0xC0;
    unsigned char tmp[2] = {vm->memory[index], vm->memory[index + 1]};

    for (int i = 0; i < size; i++) {
        arg_type[i] = (tmp[0] & mv) >> (6 - (i * 2));
        my_printf("arg_type[%d] = %d\n", i, arg_type[i]);
        mv = mv >> 2;
    }
    get_sti_arg_type_cut(arg_type, size);
    return (arg_type);
}

int get_value_sti(vm_t *vm, unsigned char arg, int *index)
{
    long long int value = 0;

    if (arg == REG_SIZE)
        value = vm->memory[*index];
    if (arg == DIR_SIZE) {
        value = get_32uint(&vm->memory[*index]);
        my_printf("is dirsize and value = %d\n", value);
    }
    if (arg == IND_SIZE) {
        value = get_16int(&vm->memory[*index]);
        my_printf("is indsize and value = %d\n", value);
    }
    return (int) value;
}

void my_sti(UNUSED champion_t *champion, cursor_t *cursor, vm_t *vm,
    UNUSED const op_t *op)
{
    int index = (int) get_32uint(cursor->pc.bytes);
    my_printf("pc = %d\n", index);
    int address = index;
    unsigned char *args = get_sti_arg_type(vm, ++index, 3);
    int params[3] = {0};
    uint32_t tmp = {0};

    my_printf("index = %d\n", index);
    index++;
    for (int i = 0; i < 3; i++) {
        params[i] = get_value_sti(vm, args[i], &index);
        my_printf("params[%d] = %d\n", i, params[i]);
        index += args[i];
    }
    set_32uint(params[0], tmp.bytes);
    address += (params[1] + params[2]) % IDX_MOD;
    for (int i = 0; i < 4; i++) {
        vm->memory[(address + i) % MEM_SIZE] = tmp.bytes[i];
    }
    free(args);
    set_32uint(++index % MEM_SIZE, cursor->pc.bytes);
}
