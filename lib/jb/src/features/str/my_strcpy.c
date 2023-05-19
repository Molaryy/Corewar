/*
** EPITECH PROJECT, 2022
** my_strcpy
** File description:
** a function that copies a whole string into another
*/


#include "jb.h"

extern char *my_strcpy(char *src)
{
    size_t len = my_strlen(src);
    char *cpy = malloc(sizeof(char) * (len + 1));

    if (!cpy || src == NULL)
        return NULL;
    cpy[len] = '\0';
    for (int i = 0; src[i] != '\0'; i++)
        cpy[i] = src[i];
    return cpy;
}
