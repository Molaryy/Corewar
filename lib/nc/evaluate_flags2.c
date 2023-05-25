/*
** EPITECH PROJECT, 2023
** evaluate_flags2.c
** File description:
** continuation of evaluate_flags.c
*/
#include <stdlib.h>

#include "flags.h"

char *init_length_modifier(void);

specifier_t null_specifier(void)
{
    specifier_t sp;

    sp.flag = '\0';
    sp.min_width = 0;
    sp.precision = 6;
    sp.length_modifier = init_length_modifier();
    sp.conversion_specifier = '\0';
    return sp;
}
