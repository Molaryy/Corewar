/*
** EPITECH PROJECT, 2023
** B-PSU-200-REN-2-1-42sh-mohammed.jbilou
** File description:
** print_link.c
*/

#include "link.h"
#include "jb.h"

void print_str_link(link_t *link)
{
    for (; link ; link = link->next) {
        my_printf("%s\n", link->data);
    }
}
