/*
** EPITECH PROJECT, 2022
** my_strdup task01
** File description:
** This will copy a string to another char array
*/

#include <stdlib.h>

int my_strlen(char const *str);

char * my_strdup(char const *src)
{
    char * res;
    unsigned int i = 0;

    res = malloc(sizeof(char) * (my_strlen(src) + 1));
    while (src[i] != '\0') {
        res[i] = src[i];
        i++;
    }
    res[i] = '\0';
    return res;
}
