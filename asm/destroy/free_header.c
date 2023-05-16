/*
** EPITECH PROJECT, 2023
** PROJECT
** File description:
** free_header
*/

#include "asm.h"
#include "jb.h"

void free_header(file_t *file, parser_t *parser)
{
    free_array_str(file->origin_file);
    free(file->body);
    free(file->header);
    free(file);
    free(parser);
}