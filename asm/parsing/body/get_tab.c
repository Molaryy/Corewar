/*
** EPITECH PROJECT, 2023
** PROJECT
** File description:
** get_tab
*/

#include "jb.h"
#include "asm.h"

extern char **get_tab(char **pars, size_t start)
{
    char **tab = NULL;

    if (pars[1] != NULL)
        tab = cpy_tab(pars, start);
    return tab;
}
