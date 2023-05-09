/*
** EPITECH PROJECT, 2023
** j_str_cat.c
** File description:
** str_cat
*/

#include "jb.h"

char *j_strcat(char const *dest, char const *src)
{
    int len_dest = 0;
    int len_src = 0;
    char *res = NULL;
    int i = 0;

    if (src != NULL)
        len_src = my_strlen(src);
    if (dest != NULL) {
        len_dest = my_strlen(dest);
        res = malloc(sizeof(char) * ((len_dest + len_src) + 1));
        for (; dest[i] != '\0'; i++)
            res[i] = dest[i];
    }
    for (int j = 0; src[j] != '\0'; j++, i++)
        res[i] = src[j];
    res[len_dest + len_src] = '\0';
    return res;
}
