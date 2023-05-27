/*
** EPITECH PROJECT, 2023
** corewar/src/process/process.c
** File description:
** handles processes
*/

#include "core.h"

process_t **init_memory(info_corewar_t *info)
{
    process_t **processes = malloc(sizeof(process_t) * MEM_SIZE);

    for (int i = 0; i < MEM_SIZE; i++)
        processes[i] = NULL;
    for (int i = 0; i <= info->nb_champions; i++) {
        init_processes(&processes[i], info->champions[i]);
    }
    return processes;
}

void init_processes(process_t **processes, champion_t champion)
{
    for (unsigned int i = 0; i < champion.stack.code_size; i++) {
        processes[i] = init_process(champion.loaded_addr, &i,
            champion.stack.code);
    }
}

process_t *init_process(int loaded_addr, unsigned int *index,
    unsigned char *code)
{
    process_t *process = process_create_null(loaded_addr + *index + 1);

    process->operation = get_op(code[*index]);
    (*index)++;
    return process;
}
