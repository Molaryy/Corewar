/*
** EPITECH PROJECT, 2023
** PROJECT
** File description:
** main_compiler.c
*/

#include "jb.h"
#include "asm.h"
#include "parser.h"

static size_t parsing_compiler(parser_t *parser, file_t *file, char *filepath)
{
    if (!parse_body(file, filepath))
        return FAILURE;
    if (!check_instruction_number_arguments(file->body, parser))
        return FAILURE;
    if (!add_labels_to_link(file->body))
        return FAILURE;
    return SUCCESS;
}

extern size_t compiler(char *filepath)
{
    file_t *file = malloc(sizeof(file_t));
    file->body = malloc(sizeof(body_t));
    file->header = malloc(sizeof(header_t));
    parser_t *parser = NULL;

    if (!init_compiler(file, parser))
        return FAILURE;
    if (!detect_file_extension(filepath))
        return FAILURE;
    if (!(parser = init_parser_reference(".instructions.txt")))
        return FAILURE;
    if (parse_header(file, filepath) > 0)
        return FAILURE;
    if (parsing_compiler(parser, file, filepath) == FAILURE)
        return FAILURE;
    cor_file(filepath, file);
    return SUCCESS;
}
