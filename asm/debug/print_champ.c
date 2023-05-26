/*
** EPITECH PROJECT, 2023
** PROJECT
** File description:
** print_champ
*/

#include "jb.h"
#include "asm.h"

extern void print_champion(champ_t *champ, size_t len)
{
    for (size_t i = 0; i < len; i++) {
        my_printf("-----NEW-----\n");
        my_printf("LABEL: [%s] | i = [%d]\n", champ[i].label, champ[i].index);
        my_printf("NB PARAMS: %d\n", champ[i].nbParams);
        my_printf("INSTRUCTION: %s\n", champ[i].paramName);
        my_printf("ARGS: ");
        print_linked_tab(champ[i].params);
        my_printf("\n[%d]-[%d]-[%d]\n", champ[i].isIndex[0],
        champ[i].isIndex[1], champ[i].isIndex[2]);
        my_printf("Is label: [%d]-[%d]-[%d]\n", champ[i].isLabel[0],
        champ[i].isLabel[1], champ[i].isLabel[2]);
        my_printf("\n-----END-----\n\n");
    }
}
