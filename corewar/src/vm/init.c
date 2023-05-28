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
    info->vm.memory = malloc(sizeof(unsigned char) * MEM_SIZE);
    for (int i = 0; i < MEM_SIZE; i++)
        info->vm.memory[i] = 0;
    for (int i = 0; i <= info->nbr_champions; i++) {
        my_strcat_cust(info->vm.memory, info->champions[i].stack.code,
            info->champions[i].loaded_addr, info->champions[i].
            stack.code_size);
        info->champions[i].cursor_head = cursor_init(info, info->champions[i].
            loaded_addr);
        info->champions[i].cursor_tail = info->champions[i].cursor_head;
    }
}

void init_vm(info_corewar_t *info)
{
    vm_t vm = {0};

    info->vm = vm;
    init_memory(info);
    info->vm.cycle_to_die = CYCLE_TO_DIE;
    info->vm.current_cycle = 0;
    info->vm.nbr_live = 0;
}
