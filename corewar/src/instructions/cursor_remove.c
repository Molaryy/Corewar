/*
** EPITECH PROJECT, 2023
** instructions
** File description:
** cursor_remove
*/
#include "cursors.h"
#include <stdlib.h>

static void cursor_remove_node(cursor_t *list, cursor_node_t *node)
{
    list->size--;
    if (list->first == node)
        list->first = node->next;
    if (list->end == node)
        list->end = node->prev;
    if (node->prev != NULL)
        node->prev->next = node->next;
    if (node->next != NULL)
        node->next->prev = node->prev;
    node->next = NULL;
    node->prev = NULL;
    free(node);
}

void cursor_remove(cursor_t *list)
{
    if (!list)
        return;
    cursor_remove_node(list, list->first);
    return;
}

void cursor_remove_pos(cursor_t *list, long long position)
{
    cursor_node_t *node;

    if (!list || !list->first)
        return;
    node = list->first;
    while (node) {
        if (node->position == position) {
            cursor_remove_node(list, node);
            return;
        }
        node = node->next;
    }
    return;
}
