/*
** EPITECH PROJECT, 2023
** PROJECT
** File description:
** get_body
*/

#include "asm.h"
#include "jb.h"

static char **get_body(char **fileTab)
{
    for (size_t i = 0; fileTab[i] ; i++)
        fileTab[i] = clean_string(fileTab[i]);
    return fileTab;
}

bool parse_body(file_t *file, char *filepath)
{
    char **fileTab = get_file(filepath);

    file->body->body = get_body(fileTab);
    return true;
}
