/*
** EPITECH PROJECT, 2022
** pushwap
** File description:
** pushwap
*/

#include "link.h"

size_t link_len(link_t *link)
{
    size_t size = 0;

    if (link == NULL)
        return 0;
    for (; link; link = link->next)
        size++;
    return size;
}
