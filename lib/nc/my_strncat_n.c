/*
** EPITECH PROJECT, 2023
** my_strncat_n.c
** File description:
** same as strncat but mallocs the string
*/

#include "nc.h"

char *my_strncat_n(char *left, char *right, int n)
{
    int len_left = my_strlen(left);
    int len_right = my_strlen(right);
    int res_len = 0;
    char *res = malloc(sizeof(char) * (len_left + len_right + 1));

    for (int i = 0; i < len_left; i++, res_len++)
        res[i] = left[i];
    for (int i = 0; i < len_right && i < n; i++, res_len++)
        res[res_len] = right[i];
    res[res_len] = '\0';
    return res;
}
