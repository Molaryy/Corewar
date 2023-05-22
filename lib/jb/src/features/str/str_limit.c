/*
** EPITECH PROJECT, 2023
** PROJECT
** File description:
** str_limit
*/

#include "jb.h"

static size_t start_from_separator(char *str, char const *separator)
{
    size_t count = 0;

    for (size_t i = 0; str[i]; i++) {
        if (!is_separator(str[i], separator))
            break;
        count++;
    }
    return count;
}

static bool there_is_a_separator(char *str, char const *separators)
{
    for (size_t i = 0; separators[i]; i++) {
        if (str_contains_char(str, separators[i]))
            return true;
    }
    return false;
}

extern char *remove_after_separator(char *str, char const *separators)
{
    char *cpy = NULL;
    size_t start = start_from_separator(str, separators);

    if (!there_is_a_separator(str, separators)
    || !is_separator(str[0], separators))
        return str;
    cpy = malloc(sizeof(char) * (start + 1));
    if (!cpy)
        return NULL;
    for (size_t i = 0; str[i] && is_separator(str[i], separators); i++)
        cpy[i] = str[i];
    cpy[start] = '\0';
    return cpy;
}
