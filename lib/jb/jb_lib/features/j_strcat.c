/*
** EPITECH PROJECT, 2023
** j_str_cat.c
** File description:
** str_cat
*/

#include "jb.h"

static char *copy_dest(char *dest, size_t len_dest, size_t len_src, size_t *i)
{
    char *res = NULL;

    if (dest != NULL) {
        len_dest = my_strlen(dest);
        res = malloc(sizeof(char) * ((len_dest + len_src) + 1));
        if (res == NULL)
            return NULL;
        for (; dest[*i] != '\0'; *i += 1)
            res[*i] = dest[*i];
    }
    return res;
}

char *j_strcat(char const *dest, char const *src)
{
    size_t len_dest = 0;
    size_t len_src = 0;
    char *res = NULL;
    size_t i = 0;

    if (src != NULL)
        len_src = my_strlen(src);
    res = copy_dest(dest, len_dest, len_src, &i);
    if (res == NULL)
        return NULL;
    for (int j = 0; src[j] != '\0'; j++, i++)
        res[i] = src[j];
    res[len_dest + len_src] = '\0';
    return res;
}
