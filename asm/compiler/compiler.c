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
    body_t *body = malloc(sizeof(body_t));
    header_t *header = malloc(sizeof(header_t));

    if (!init_compiler(body, header))
        return FAILURE;
    if (!detect_file_extension(filepath))
        return FAILURE;
    return SUCCESS;
}
