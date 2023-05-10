/*
** EPITECH PROJECT, 2022
** pushwap
** File description:
** pushwap
*/

#include "link.h"

void link_rm_beg_node(link_t **node)
{
    for (; (*node)->prev != NULL; *node = (*node)->prev);

    if ((*node)->next != NULL) {
        *node = (*node)->next;
        (*node)->prev = NULL;
        free((*node)->prev);
    } else {
        free(*node);
        (*node) = NULL;
    }
}

static void delete_last_node(link_t *link)
{
    for (; link->prev != NULL; link = link->prev);
    for (; link->next != NULL; link = link->next);
    link->prev->next = NULL;
    free(link);
}

link_t *delete_mid_node(link_t *link, size_t position)
{
    link_t *node_to_delete = link;

    if (position > link_len(link))
        return link;
    if (position == 1) {
        link_rm_beg_node(&link);
        return link;
    }
    if (position == link_len(link)) {
        delete_last_node(link);
        return link;
    }
    for (size_t i = 1; i < position; i++) {
        node_to_delete = node_to_delete->next;
    }
    node_to_delete->prev->next = node_to_delete->next;
    node_to_delete->next->prev = node_to_delete->prev;
    free(node_to_delete);
    return link;
}
