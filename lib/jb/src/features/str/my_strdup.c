/*
** EPITECH PROJECT, 2023
** my_strdup
** File description:
** dup
*/

#include "jb.h"

char *my_strdup(char const *src)
{
    char *copy;
    int i = 0;

    copy = malloc(sizeof(char) * (my_strlen(src) + 1));
    if (copy == NULL)
        return NULL;
    while (src[i]) {
        copy[i] = src[i];
        i++;
    }
    copy[i] = '\0';
    return copy;
}
