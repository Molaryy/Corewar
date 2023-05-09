/*
** EPITECH PROJECT, 2023
** PROJECT
** File description:
** main_compiler.c
*/

#include "jb.h"
#include "asm.h"

size_t compiler(char const *filepath)
{
    if (!detect_file_extension(filepath))
        return FAILURE;
    return SUCCESS;
}
