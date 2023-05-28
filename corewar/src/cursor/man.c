/*
** EPITECH PROJECT, 2023
** corewar/src/cursor/man.c
** File description:
** linked list manipulation specifically for the cursor_t struct in the
** corewar project
*/

#include "core.h"

void cursor_push_head(cursor_t **head, int index)
{
    cursor_t *new = malloc(sizeof(cursor_t));

    set_32uint(index, new->pc.bytes);
    if (*head != NULL)
        (*head)->prev = new;
    new->next = *head;
    new->prev = NULL;
    *head = new;
}

void cursor_pop(cursor_t *current, cursor_t **head, cursor_t **tail)
{
    if (current == NULL)
        return;
    if (current->prev != NULL)
        current->prev->next = current->next;
    if (current->next != NULL)
        current->next->prev = current->prev;
    if (current == *tail)
        *tail = current->prev;
    if (current == *head)
        *head = current->next;
    free(current);
}

void cursor_pop_cascade(cursor_t *current, cursor_t **head)
{
    cursor_t *tmp = *head;

    if (*head == NULL || current == NULL)
        return;
    while (tmp != current) {
        if (tmp == NULL)
            break;
        *head = tmp->next;
        free(tmp);
        tmp = *head;
    }
    if (current->next != NULL)
        current->next->prev = NULL;
    *head = current->next;
    free(current);
}
