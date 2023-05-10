/*
** EPITECH PROJECT, 2023
** PROJECT
** File description:
** my_strlen.c
*/

#include "jb.h"

size_t my_strlen(char const *str)
{
    size_t i = 0;

    for ( ; str[i] ; i++);
    return i;
}
