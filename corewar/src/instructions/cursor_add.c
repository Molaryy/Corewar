/*
** EPITECH PROJECT, 2023
** instructions
** File description:
** cursor_add
*/
#include "cursors.h"
#include <stdlib.h>

void cursor_add(cursor_t *list, long long position, int nb_cycle)
{
    cursor_node_t *node;

    if (!list)
        return;
    node = malloc(sizeof(*node));
    if (!node)
        return;
    node->position = position;
    node->nb_cycle = nb_cycle;
    node->check = false;
    node->prev = NULL;
    node->next = NULL;
    list->size++;
    if (list->first == NULL) {
        list->first = node;
        list->end = node;
        return;
    }
    list->end->next = node;
    node->prev = list->end;
    list->end = node;
}
