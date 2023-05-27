/*
** EPITECH PROJECT, 2023
** corewar/src/process/process.c
** File description:
** handles processes
*/

#include "core.h"

void init_memory(info_corewar_t *info)
{
    process_t *processes = malloc(sizeof(process_t) * MEM_SIZE);

    info->vm.memory = malloc(sizeof(unsigned char) * MEM_SIZE);
    for (int i = 0; i < MEM_SIZE; i++)
        processes[i] = process_create_null();
}
