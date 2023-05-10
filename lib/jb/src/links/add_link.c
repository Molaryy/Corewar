/*
** EPITECH PROJECT, 2022
** link
** File description:
** link_add
*/

#include "link.h"

void add_link_end(link_t **link, void *data)
{
    link_t *tp;
    link_t *new_node = malloc(sizeof(link_t));

    if (new_node == NULL){
        my_printf("add_link_end() has malloc NULL");
        return;
    }
    new_node->prev = NULL;
    new_node->data = data;
    new_node->next = NULL;
    tp = *link;
    for (; tp->next != NULL; tp = tp->next);
    tp->next = new_node;
    new_node->prev = tp;
}
