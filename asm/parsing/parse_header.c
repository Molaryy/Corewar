/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** Pars_header
*/

#include "asm.h"
#include "jb.h"

void parse_header(file_t *file, char *filepath)
{
    file->origin_file = get_file(filepath);
    my_printf("%t", file->origin_file);
}