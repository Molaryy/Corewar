/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** Pars_header
*/

#include "asm.h"

void print_file(file_t *file)
{
    for (int i = 0; file->origin_file[i]; i++)
        printf("%s\n", file->origin_file[i]);
}

void parse_header(file_t *file, char *filepath)
{
    file->origin_file = get_file(filepath);
    print_file(file);
}