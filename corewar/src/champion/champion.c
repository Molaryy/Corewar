/*
** EPITECH PROJECT, 2023
** corewar/src/champion/champion.c
** File description:
** functions for the champion entity
*/

#include "core.h"

champion_t champion_create(info_corewar_t *info, int prog_nbr, int loaded_addr,
    char *filename)
{
    champion_t champ;
    cursor_t *tmp;

    champ.prog_nbr = prog_nbr;
    champ.loaded_addr = loaded_addr;
    champ.stack = stack_create(&champ, filename);
    champ.last_live_cycle = 0;
    tmp = cursor_init(info, loaded_addr);
    champ.cursor_head = tmp;
    champ.cursor_tail = tmp;
    for (int j = 0; j < REG_NUMBER; j++)
        set_32uint(0, champ.registers[j].bytes);
    set_32uint(prog_nbr, champ.registers[0].bytes);
    return champ;
}
