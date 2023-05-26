/*
** EPITECH PROJECT, 2022
** ll manipulation
** File description:
** This is a file used for string manipulation
*/

#include <stdlib.h>

#include "nc.h"
#include "str_linked_list.h"

int free_str_ll(str_ll_t *node)
{
    str_ll_t *to_free = NULL;

    while (node->next != NULL) {
        to_free = node;
        if (node->next != NULL) {
            node = node->next;
            free(to_free);
        } else {
            free(node);
        }
    }
    return 0;
}

str_ll_t *iterate_n(str_ll_t *str, int n)
{
    for (int i = 0; i < n; i++) {
        if (str != NULL)
            str = str->next;
    }
    return str;
}

char get_last_ll(str_ll_t *str)
{
    while (str->next != NULL) {
        str = str->next;
    }
    return str->c;
}

str_ll_t *iterate_ll(str_ll_t *node, int i)
{
    str_ll_t *begin = node;
    str_ll_t *to_free = NULL;

    for (int j = 0; j < i; j++) {
        node = node->next;
    }
    node->next = NULL;
    if (node == NULL)
        return begin;
    free_str_ll(node);
    return begin;
}
