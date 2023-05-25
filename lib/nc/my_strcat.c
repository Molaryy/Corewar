/*
** EPITECH PROJECT, 2022
** my_strcat
** File description:
** Day 06 task not done
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strcat(char *dest, char const *src)
{
    int dest_len = my_strlen(dest);
    unsigned int i;

    for ( i = 0 ; src[i] != '\0' ; i++)
        dest[dest_len + i] = src[i];
    dest[dest_len + i] = '\0';
    return dest;
}

char *my_strcat_n(char const *dest, char const *src)
{
    int dest_len = my_strlen(dest);
    int src_len = my_strlen(src);
    unsigned int i = 0;
    unsigned int j = 0;
    char *res = malloc(sizeof(char) * (dest_len + src_len + 1));

    res[dest_len + src_len] = '\0';
    for (; dest[i] != '\0'; i++)
        res[i + j] = dest[i];
    for (; src[j] != '\0'; j++)
        res[i + j] = src[j];
    return res;
}
