/*
** EPITECH PROJECT, 2023
** corewar/src/process/process.c
** File description:
** handles processes
*/

#include "core.h"

process_t *init_memory(info_corewar_t *info)
{
    process_t **processes = malloc(sizeof(process_t) * MEM_SIZE);

    for (int i = 0; i < MEM_SIZE; i++)
        processes[i] = NULL;
    for (int i = 0; i <= info->nb_champions; i++) {
        init_processes(info, &processses[i], info->champions[i]);
    }
}

process_t *init_process(int loaded_addr, unsigned int *index,
    unsigned char *code)
{
    process_t *process = malloc(sizeof(process_t));

    process->pc = loaded_addr;
    process->carry = 0;
    process->cycle = 0;
    process->alive = 1;
    for (int j = 0; j < REG_NUMBER; j++)
        set_32uint(0, process->registers);
    return process;
}