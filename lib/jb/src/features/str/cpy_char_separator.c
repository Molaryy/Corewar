/*
** EPITECH PROJECT, 2023
** B-PSU-200-REN-2-1-42sh-mohammed.jbilou
** File description:
** cpy char separator
*/

#include "jb.h"

static size_t count_str_separator(char *str, char c)
{
    size_t count = 0;

    for (size_t i = 0; str[i]; i++) {
        if (str[i] != c)
            count++;
    }
    return count;
}

char *cpy_str_without_char(char *str, char c)
{
    size_t len = count_str_separator(str, c);
    char *cpy = malloc(sizeof(char) * (len + 1));
    size_t j = 0;

    if (cpy == NULL)
        return NULL;
    cpy[len] = '\0';
    for (size_t i = 0; str[i]; i++) {
        if (str[i] != c) {
            cpy[j] = str[i];
            j++;
        }
    }
    return cpy;
}
