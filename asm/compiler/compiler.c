/*
** EPITECH PROJECT, 2023
** PROJECT
** File description:
** main_compiler.c
*/

#include "jb.h"
#include "asm.h"
#include "parser.h"

size_t compiler(char *filepath)
{
    file_t *file = malloc(sizeof(file_t));
    file->body = malloc(sizeof(body_t));
    file->header = malloc(sizeof(header_t));
    parser_t *parser = NULL;

    if (!init_compiler(file))
        return FAILURE;
    if (!detect_file_extension(filepath))
        return FAILURE;
    if (!(parser = init_parser_reference(".instructions.txt")))
        return FAILURE;
    if (parse_header(file, filepath) > 0)
        return FAILURE;
    free_header(file, parser);
    return SUCCESS;
}
