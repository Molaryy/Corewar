/*
** EPITECH PROJECT, 2023
** PROJECT
** File description:
** create_champ
*/

#include "asm.h"

extern champ_t *init_champ(champ_t *champ, size_t len)
{
    for (size_t i = 0; i < len; i++) {
        champ[i].index = 0;
        champ[i].isIndex[0] = false;
        champ[i].isIndex[1] = false;
        champ[i].isIndex[2] = false;
        champ[i].label = NULL;
        champ[i].nbParams = 0;
        champ[i].paramName = NULL;
        champ[i].params = NULL;
    }
    return champ;
}
