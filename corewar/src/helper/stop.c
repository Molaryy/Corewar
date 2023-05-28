/*
** EPITECH PROJECT, 2023
** corewar/src/helper/stop.c
** File description:
** stop the program and free everything needed
*/

#include "core.h"

void stop(info_corewar_t *info, int status)
{
    for (int i = 0; i <= info->nbr_champions; i++) {
        free(info->champions[i].name);
        free(info->champions[i].stack.code);
        cursor_pop_cascade(info->champions[i].cursor_tail,
            &info->champions[i].cursor_head);
    }
    free(info->vm.memory);
    exit(status);
}
