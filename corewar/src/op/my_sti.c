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
            case 0:
                arg_type[i] = REG_SIZE;
                break;
            case 2:
                arg_type[i] = DIR_SIZE;
                break;
            case 3:
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

    for (int i = 0; i < size; i++) {
        arg_type[i] = (vm->memory[index + i] & mv) >> (6 - (i * 2));
        // my_printf("arg_type[%d] = %d\n", i, arg_type[i]);
        mv = mv >> 2;
    }
    get_sti_arg_type_cut(arg_type, size);
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
    unsigned char *args = get_sti_arg_type(vm, ++index, 3);
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
