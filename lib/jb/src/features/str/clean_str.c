/*
** EPITECH PROJECT, 2023
** PROJECT
** File description:
** clean_str
*/

#include "jb.h"

static size_t count_str_no_separators(char const *str, char const *separators)
{
    size_t count = 0;

    if (!str || !separators)
        return 0;
    for (size_t i = 0; str[i]; i++) {
        if (is_separator(str[i], separators))
            count++;
    }
    return count;
}

extern char *str_set(char *str)
{
    for (size_t i = 0; str[i]; i++)
        str[i] = '\0';
    return str;
}

extern char *clean_str(char const *str, char const *separators)
{
    size_t len = count_str_no_separators(str, separators);
    char *cpy = NULL;

    if (len == 0)
        return NULL;
    cpy = malloc(sizeof(char) * (len + 1));
    if (!cpy)
        return NULL;
    cpy[len] = '\0';
    for (size_t i = 0, j = 0; str[i]; i++) {
        if (is_separator(str[i], separators)) {
            cpy[j] = str[i];
            j++;
        }
    }
    return cpy;
}
