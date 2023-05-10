/*
** EPITECH PROJECT, 2023
** free_links.c
** File description:
** free_links
*/

#include "link.h"

void free_links(link_t **head_ref)
{
    link_t *current = *head_ref;
    link_t *tmp = NULL;

    while (current != NULL) {
        tmp = current;
        current = current->next;
        free(tmp);
        tmp = NULL;
    }
    *head_ref = NULL;
}
