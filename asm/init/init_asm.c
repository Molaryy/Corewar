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

static parser_t *init_body(body_t *body, parser_t *pars)
{
    body->bodyArray = NULL;
    body->labels = NULL;
    pars = NULL;
    return pars;
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
    init_body(file->body, pars);
    if (!init_file(file))
        return false;
    file->nbComment = 0;
    file->nbName = 0;
    return true;
}
