/*
** EPITECH PROJECT, 2022
** pushwap
** File description:
** pushwap
*/

#include "link.h"

extern size_t link_len(link_t *link)
{
    size_t size = 0;
    link_t *tmp = link;

    if (link == NULL)
        return 0;
    for (; tmp; tmp = tmp->next)
        size++;
    return size;
}
