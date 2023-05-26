/*
** EPITECH PROJECT, 2023
** my_strdup_f.c
** File description:
** This will duplicate the string and free the source string
*/

#include <stdlib.h>

int my_strlen(char const *str);

char * my_strdup_f(char *src)
{
    char * res;
    unsigned int i = 0;

    res = malloc(sizeof(char) * (my_strlen(src) + 1));
    while (src[i] != '\0') {
        res[i] = src[i];
        i++;
    }
    res[i] = '\0';
    free(src);
    return res;
}
