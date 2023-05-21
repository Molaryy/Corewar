/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** init asm
*/

#include "asm.h"

static bool init_header(header_t *header)
{
    if (header == NULL)
        return false;
    return true;
}

static bool init_body(body_t *body, parser_t *pars)
{
    if (body == NULL)
        return false;
    body->bodyArray = NULL;
    body->labels = NULL;
    pars = NULL;
    return true;
}

static bool init_file(file_t *file)
{
    if (file == NULL)
        return false;
    file->origin_file = NULL;
    file->parsing_file = NULL;
    file->body->labels = NULL;
    return true;
}

extern bool init_compiler(file_t *file, parser_t *pars)
{
    if (!init_header(file->header))
        return false;
    if (!init_body(file->body, pars))
        return false;
    if (!init_file(file))
        return false;
    return true;
}
