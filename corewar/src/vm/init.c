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

void init_vm(info_corewar_t *info)
{
    init_memory(info);
    for (int i = 0; i <= info->nb_champions; i++)
        my_strcat_cust(info->vm.memory, info->champions[i].stack.code,
            info->champions[i].loaded_addr, info->champions[i].stack.code_size);
}
