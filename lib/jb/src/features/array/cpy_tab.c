/*
** EPITECH PROJECT, 2023
** PROJECT
** File description:
** cpy_tab
*/

#include "jb.h"

extern char **cpy_tab(char **tab, size_t start)
{
    int lines = count_tab(tab) - start;
    char **cpy = malloc(sizeof(char *) * (lines + 1));

    if (!cpy)
        return NULL;
    for (int i = start, j = 0; tab[i] != NULL; i++, j++)
        cpy[j] = my_strcpy(tab[i]);
    cpy[lines] = NULL;
    return cpy;
}
