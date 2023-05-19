/*
** EPITECH PROJECT, 2022
** link
** File description:
** create_link
*/


#include "link.h"

extern link_t *create_link(link_t *node, void *data)
{
    link_t *new_node = malloc(sizeof(link_t));

    if (new_node == NULL){
        my_printf("add_link_end() has malloc NULL\n");
        return NULL;
    }
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
    node = new_node;
    return node;
}
