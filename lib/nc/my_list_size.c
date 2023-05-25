/*
** EPITECH PROJECT, 2022
** my_list_size
** File description:
** This will return the number of nodes there
** are in a linked list
*/

#include <stdlib.h>

#include "str_linked_list.h"

int my_list_size(str_ll_t *begin)
{
    int i = 0;

    while (begin != NULL) {
        i++;
        begin = begin->next;
    }
    return i;
}
