/*
** EPITECH PROJECT, 2023
** corewar/src/op/my_sti.c
** File description:
** sti
*/

#include "core.h"

unsigned char *get_sti_arg_type(vm_t *vm, int index)
{
    unsigned char *arg_type = malloc(sizeof(unsigned char) * 3);

    arg_type[0] = (vm->memory[index] & PARAM_TYPE_MASK_1) >> 6;
    arg_type[1] = (vm->memory[index + 1] & PARAM_TYPE_MASK_2) >> 4;
    arg_type[2] = (vm->memory[index + 2] & PARAM_TYPE_MASK_3) >> 2;
    for (int i = 0; i < 3; i++) {
        switch (arg_type[i]) {
            case 0:
                arg_type[i] = REG_SIZE;
                break;
            case 1:
                arg_type[i] = DIR_SIZE;
                break;
            case 2:
                arg_type[i] = IND_SIZE;
                break;
            default: break;
        }
    }
    return (arg_type);
}

int get_value_sti(vm_t *vm, unsigned char arg, int *index)
{
    long long int value = 0;
    uint32_t tmp = {0};

    if (arg == REG_SIZE) {
        for (int i = 0; i < REG_SIZE; i++)
            tmp.bytes[i] = vm->memory[(*index + i) % MEM_SIZE];
        value = get_32uint(tmp.bytes);
        *index += REG_SIZE;
    } else {
        for (int i = 0; i < REG_SIZE; i++)
            tmp.bytes[i] = vm->memory[(*index + i) % MEM_SIZE];
        value = get_32uint(tmp.bytes);
        *index += REG_SIZE;
    }
    return (int) value;
}

void my_sti(UNUSED champion_t *champion, cursor_t *cursor, vm_t *vm,
    UNUSED const op_t *op)
{
    my_printf("sti\n");
    int index = (int) get_32uint(cursor->pc.bytes);
    int address = index;
    unsigned char *args = get_sti_arg_type(vm, ++index);
    int arg1 = get_value_sti(vm, args[0], &index);
    int arg2 = get_value_sti(vm, args[1], &index);
    int arg3 = get_value_sti(vm, args[2], &index);
    uint32_t tmp = {0};

    address += (arg2 + arg3) % IDX_MOD;
    set_32uint((long long int) arg1, tmp.bytes);
    for (int i = 0; i < 4; i++) {
        my_printf("%08X\n", tmp.bytes[i]);
        vm->memory[(address + i) % MEM_SIZE] = tmp.bytes[i];
    }
    free(args);
    set_32uint(++index % MEM_SIZE, cursor->pc.bytes);
}
