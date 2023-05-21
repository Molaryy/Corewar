/*
** EPITECH PROJECT, 2023
** PROJECT
** File description:
** free_header
*/

#include "asm.h"
#include "jb.h"
#include "parser.h"

extern void free_header(file_t *file, parser_t *parser)
{
    free_body(file);
    free_array_str(file->origin_file);
    if (file->body)
        free(file->body);
    if (file->header)
        free(file->header);
    if (file)
        free(file);
    if (parser) {
        free_parser(parser);
        free(parser);
    }
}
