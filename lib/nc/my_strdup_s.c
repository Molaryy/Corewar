/*
** EPITECH PROJECT, 2022
** my_strdup_s
** File description:
** This will copy a string to another char array
*/

#include <stdlib.h>

#include "nc.h"

int my_strlen(char const *str);

char *my_strdup_s(char const *src, int index)
{
    char * res;
    unsigned int i = 0;

    res = malloc(sizeof(char) * (my_strlen(src) + 1 - index));
    while (src[i + index] != '\0') {
        res[i] = src[i + index];
        i++;
    }
    res[i] = '\0';
    return res;
}
