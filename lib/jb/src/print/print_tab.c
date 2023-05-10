/*
** EPITECH PROJECT, 2022
** my_swap.c
** File description:
** Swaps the content of 2 int, whose addresses are given as a prmtr
*/

#include "jb.h"

void print_tab(char **tab)
{

    if (tab == NULL){
        my_printf("tab = NULL\n");
        return;
    }
    for (size_t i = 0; tab[i]; i++)
        my_printf("%s\n", tab[i]);
}
