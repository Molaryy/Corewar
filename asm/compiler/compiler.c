/*
** EPITECH PROJECT, 2023
** PROJECT
** File description:
** main_compiler.c
*/

#include "jb.h"
#include "asm.h"
#include "parser.h"

size_t compiler(char const *filepath)
{
    body_t *body = malloc(sizeof(body_t));
    header_t *header = malloc(sizeof(header_t));
    parser_t *parser = NULL;

    if (!init_compiler(body, header))
        return FAILURE;
    if (!detect_file_extension(filepath))
        return FAILURE;
    if (!(parser = init_parser_reference(".instructions.txt")))
        return FAILURE;
    return SUCCESS;
}
