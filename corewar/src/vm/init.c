/*
** EPITECH PROJECT, 2023
** corewar/src/vm/init.c
** File description:
** initializers for vm struct
*/

#include "core.h"

void my_strcat_cust(unsigned char *dest, unsigned char *src, unsigned int
    start_index, unsigned int size)
{
    unsigned int j = 0;

    for (unsigned int i = start_index; j < size; i++, j++)
        dest[i] = src[j];
}

void init_memory(info_corewar_t *info)
{
    info->vm.processes = malloc(sizeof(process_t) * MEM_SIZE);
    info->vm.memory = malloc(sizeof(unsigned char) * MEM_SIZE);
    for (int i = 0; i < MEM_SIZE; i++) {
        info->vm.memory[i] = 0;
        info->vm.processes[i] = process_create_null((i + 1) % MEM_SIZE);
    }
}

void read_code(unsigned char *memory, int *index_memory, vm_t *vm, int prog_num)
{
    vm->processes[vm->processes_size].operation = get_op(memory
        [*index_memory]);
    vm->processes[vm->processes_size].pc = *index_memory + vm->processes[
        vm->processes_size].operation.nbr_args + 1;
    vm->processes[vm->processes_size].if_carry = FALSE;
    vm->processes[vm->processes_size].index_id = *index_memory;
    if (memory[*index_memory] == 9)
        vm->processes[vm->processes_size].if_carry = TRUE;
    (vm->processes_size)++;
}

void init_vm(info_corewar_t *info)
{
    init_memory(info);
    for (int i = 0; i <= info->nb_champions; i++) {
        my_strcat_cust(info->vm.memory, info->champions[i].stack.code,
            info->champions[i].loaded_addr, info->champions[i].stack.code_size);
        cursor_add(info->cursors, info->champions[i].loaded_addr, 0,
            info->champions[i].loaded_addr);
    }
    info->vm.processes_size = 0;
    for (int i = 0; i < MEM_SIZE; i++)
        read_code(info->vm.memory, &i, &info->vm, get_champ_prog_nbr(info, i));
    my_printf("first case = %d\n", info->vm.memory[0]);
    my_printf("2nd case = %d\n", info->vm.memory[1]);
}
