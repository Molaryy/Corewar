/*
** EPITECH PROJECT, 2023
** PROJECT
** File description:
** remove_beg_str
*/

#include "jb.h"

static size_t start_from_separator(char *str, char const *separator)
{
    size_t count = 0;

    if (is_separator(str[0], separator))
        return 0;
    for (size_t i = 0; !is_separator(str[i], separator); i++)
        count++;
    return count;
}

extern char *remove_str_beg_separator(char *str, char const *separators)
{
    char *cpy = NULL;
    size_t start = start_from_separator(str, separators);

    if (is_separator(str[0], separators))
        return str;
    cpy = malloc(sizeof(char) * (my_strlen(str) - (start - 1)));
    if (!cpy)
        return NULL;
    for (size_t i = start, j = 0; str[i]; i++, j++)
        cpy[j] = str[i];
    cpy[my_strlen(str) - start] = '\0';
    return cpy;
}
