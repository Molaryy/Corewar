/*
** EPITECH PROJECT, 2023
** corewar/src/vm/init.c
** File description:
** initializers for vm struct
*/
#include "core.h"

void increment_cycles(info_corewar_t *info)
{
    info->vm.current_cycle++;
    info->vm.cycle_to_die++;
    info->vm.total_cycles++;
}

void run_vm(info_corewar_t *info)
{
    while (check_game_over(info) == FALSE) {

        increment_cycles(info);
    }
}
