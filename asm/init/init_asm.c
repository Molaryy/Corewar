/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** init asm
*/

#include "asm.h"

bool init_header(header_t *header)
{
    if (header == NULL)
        return false;
    header->description = NULL;
    header->name = NULL;
    return true;
}

bool init_body(body_t *body)
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

bool init_compiler(body_t *body, header_t *header)
{
    if (!init_header(header))
        return false;
    if (!init_body(body))
        return false;
    return true;
}
