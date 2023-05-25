/*
** EPITECH PROJECT, 2023
** realloc_char.c
** File description:
** this will have the realloc function for string arrays
*/

#include "nc.h"

#include <stdio.h>

int get_arrlen(char **arr)
{
    int len = 0;

    if (arr == NULL) {
        return 0;
    }
    for (; arr[len]; len++);
    return len;
}

int free_arr(char **arr)
{
    if (arr == NULL)
        return 0;

    for (size_t i = 0; arr[i]; i++)
        free(arr[i]);
    free(arr);
    return 0;
}

char **realloc_char(char **arr, char *new)
{
    int len = get_arrlen(arr);
    char **res = malloc(sizeof(char *) * (len + 2));
    int i = 0;

    res[len + 1] = NULL;
    if (arr != NULL)
        for (; arr[i] != NULL; i++)
            res[i] = my_strdup(arr[i]);
    res[i] = my_strdup(new);
    free_arr(arr);
    return res;
}

char **cust_realloc_char(char **arr, char *new)
{
    char **res = realloc_char(arr, new);

    free(new);
    return res;
}
