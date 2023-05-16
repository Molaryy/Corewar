/*
** EPITECH PROJECT, 2023
** PROJECT
** File description:
** free_body.c
*/

#include "jb.h"
#include "asm.h"
#include "parser.h"

void free_parser(parser_t *pars)
{
    for (size_t i = 0 ; i < NB_INSTRIUCTIONS ; i++) {
        if (pars[i].name) {
            free(pars[i].name);
        }
    }
}
