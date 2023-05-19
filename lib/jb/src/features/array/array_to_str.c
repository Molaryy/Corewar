/*
** EPITECH PROJECT, 2023
** array_to_str.c
** File description:
** array_to_str
*/

#include "jb.h"

extern char *array_to_str(char **array, char *separator)
{
    char *cpy = "";

    if (array == NULL)
        return NULL;
    for (size_t i = 0; array[i]; i++) {
        if (i == 0)
            continue;
        cpy = j_strcat(cpy, array[i]);
        if (array[i + 1] != NULL)
            cpy = j_strcat(cpy, separator);
    }
    return cpy;
}
