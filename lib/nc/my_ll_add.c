/*
** EPITECH PROJECT, 2022
** str linked list create node
** File description:
** This will populate a linked list and add it to the linked list
*/

#include "str_linked_list.h"

#include <stdlib.h>

str_ll_t *my_ll_add(str_ll_t *current_node, char ch)
{
    str_ll_t *new_node = malloc(sizeof(str_ll_t));
    str_ll_t *first_node = current_node;

    new_node->c = ch;
    new_node->next = NULL;
    if (current_node == NULL) {
        return new_node;
    }
    while (current_node->next != NULL) {
        current_node = current_node->next;
    }
    current_node->next = new_node;
    return first_node;
}
