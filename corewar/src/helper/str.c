/*
** EPITECH PROJECT, 2023
** corwar/src/helper/str.c
** File description:
** string helper functions
*/

#include "core.h"

int my_is_char_alphanumeric(char c)
{
    if (c >= '0' && c <= '9')
        return TRUE;
    if (c >= 'a' && c <= 'z')
        return TRUE;
    if (c >= 'A' && c <= 'Z')
        return TRUE;
    if (c == '_' || c == '-' || c == ' ' || c == '\t' || c == '\n')
        return TRUE;
    return FALSE;
}

char *trim_str(char *str, int len)
{
    char *res = malloc(sizeof(char) * (len + 1));
    int j = 0;

    for (int i = 0; i < len; i++)
        if (my_is_char_alphanumeric(str[i]) == TRUE)
            res[(j)++] = str[i];
    res[j] = '\0';
    return res;
}
