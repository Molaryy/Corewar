/*
** EPITECH PROJECT, 2023
** PROJECT
** File description:
** free_str_2d
*/

#include "jb.h"

void free_array_str(char **array)
{
    if (array == NULL)
        return;
    for (size_t i = 0; array[i] ; i++)
        free(array[i]);
    free(array);
}