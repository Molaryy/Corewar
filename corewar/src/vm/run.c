/*
** EPITECH PROJECT, 2023
** corewar/src/vm/init.c
** File description:
** initializers for vm struct
*/
#include "core.h"

void run_vm(info_corewar_t *info)
{
    cursor_node_t *current = NULL;

    while (1) {
        if (info->cursors == NULL)
            return;
        current = info->cursors->first;
        while (current) {
            do_instruction(info->vm.memory, current, info->vm.processes);
            current = current->next;
        }
    }
}
