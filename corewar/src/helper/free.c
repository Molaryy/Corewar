/*
** EPITECH PROJECT, 2023
** corewar/src/helper/free.c
** File description:
** freeing functions
*/

#include "core.h"

void free_3(char *str1, char *str2, char *str3)
{
    free(str1);
    free(str2);
    free(str3);
}

void free_2(char *str1, char *str2)
{
    free(str1);
    free(str2);
}
