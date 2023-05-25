/*
** EPITECH PROJECT, 2022
** my_put_ll
** File description:
** This will print the linkedlist string in the terminal
*/

#include "str_linked_list.h"
#include <stdlib.h>

str_ll_t *my_ll_add(str_ll_t *current_node, char ch);
void my_put_nbr(int);
void my_putchar(char c);

int my_put_ll(str_ll_t *head, int *char_count)
{
    while (head != NULL) {
        my_putchar(head->c);
        (*char_count)++;
        head = head->next;
    }
    return 0;
}
