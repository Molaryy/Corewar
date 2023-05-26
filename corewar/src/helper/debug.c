/*
** EPITECH PROJECT, 2023
** corewar/src/helper/debug.c
** File description:
** debugger to display some data
*/

#include "core.h"

void display_champion(champion_t *champion)
{
    my_printf("Champion name: %s\n", champion->name);
    my_printf("Champion number: %d\n", champion->prog_nbr);
    my_printf("Champion load address: %d\n", champion->loaded_addr);
    my_printf("Champion code size: %d\n", champion->stack.code_size);
    my_printf("Champion code: ");
    for (unsigned int i = 0; i < champion->stack.code_size; i++) {
        if (i % 2 == 0)
            my_printf("%08X ", (unsigned int)champion->stack.code[i]);
        else
            my_printf("%08X\n", (unsigned int)champion->stack.code[i]);
    }
    my_printf("\n");
}

void display_info(info_corewar_t *info)
{
    my_printf("Dump: %d\n", info->dump);
    my_printf("Nb champions: %d\n", info->nb_champions);
    for (int i = 0; i <= info->nb_champions; i++) {
        display_champion(&info->champions[i]);
    }
}
