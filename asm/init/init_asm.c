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
    header->description = NULL;
    header->name = NULL;
    return true;
}

static bool init_body(body_t *body)
{
    if (body == NULL)
        return false;
    body->hexa = NULL;
    body->label_char = '\0';
    body->name = NULL;
    body->nb_param = 0;
    body->reg = false;
    body->direct = false;
    body->indirect = false;
    return true;
}

static bool init_file(file_t *file)
{
    if (file == NULL)
        return false;
    file->origin_file = NULL;
    return true;
}

bool init_compiler(file_t *file)
{
    if (!init_header(file->header))
        return false;
    if (!init_body(file->body))
        return false;
    if (!init_file(file))
        return false;
    return true;
}
