/*
** EPITECH PROJECT, 2023
** PROJECT
** File description:
** count_tab
*/

#include "jb.h"

extern size_t count_tab(char **tab)
{
    size_t count = 0;

    if (tab == NULL) {
        my_printf("tab == NULL | count_tab()\n");
        return 0;
    }
    for ( ; tab[count] ; count++);
    return count;
}
