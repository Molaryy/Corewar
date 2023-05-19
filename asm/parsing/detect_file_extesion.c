/*
** EPITECH PROJECT, 2023
** PROJECT
** File description:
** detect_file.c
*/

#include "jb.h"

extern bool detect_file_extension(char const *filepath)
{
    size_t len = my_strlen(filepath);

    if (filepath[len - 2] == '.' && filepath[len - 1] == 's')
        return true;
    return false;
}
