/*
** EPITECH PROJECT, 2022
** printf add padding
** File description:
** This will create a new linked list that adds padding to the
** left if the min width is larger than the width of the str
*/

#include <stdlib.h>

#include "str_linked_list.h"

str_ll_t *my_ll_add(str_ll_t *current_node, char ch);
int my_list_size(str_ll_t *begin);

str_ll_t *add_padding_printf(str_ll_t *memory, int min_width)
{
    str_ll_t *padding = NULL;
    str_ll_t *begin;
    int list_size = my_list_size(memory);

    if (list_size < min_width) {
        for (int j = 0; j < min_width - list_size; j++)
            padding = my_ll_add(padding, ' ');
    }
    begin = padding;
    if (padding != NULL) {
        while (padding->next != NULL)
            padding = padding->next;
        padding->next = memory;
    }
    return padding != NULL ? begin : memory;
}
