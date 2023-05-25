/*
** EPITECH PROJECT, 2023
** corewar/src/champion/champion.c
** File description:
** functions for the champion entity
*/

#include "core.h"

champion_t champion_create(int prog_nbr, int loaded_addr, char *filename)
{
    champion_t champ;

    champ.filename = filename;
    champ.prog_nbr = prog_nbr;
    champ.loaded_addr = loaded_addr;
    champ.stack = stack_create(&champ, filename);
    return champ;
}
