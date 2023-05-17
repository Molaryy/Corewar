/*
** EPITECH PROJECT, 2023
** PROJECT
** File description:
** get_body
*/

#include "asm.h"
#include "jb.h"

static size_t count_lines_body(char **file)
{
    size_t count = 0;

    for (size_t i = 0; file[i] ; i++) {
        if (file[i][0] != '.' && file[i][0] != '#')
            count++;
    }
    return count;
}

static char **get_body(char **file)
{
    size_t len = 0;
    char **cpy = NULL;

    for (size_t i = 0; file[i] ; i++)
        file[i] = clean_string(file[i]);
    len = count_lines_body(file);
    if (!(cpy = malloc(sizeof(char *) * (len + 1))))
        return NULL;
    cpy[len] = NULL;
    for (size_t i = 0, j = 0; file[i] ; i++) {
        if (file[i][0] != '.' && file[i][0] != '#') {
            cpy[j] = my_strcpy(file[i]);
            j++;
        }
    }
    free_array_str(file);
    return cpy;
}

bool parse_body(file_t *file, char *filepath)
{
    char **fileTab = get_file(filepath);

    file->body->bodyArray = get_body(fileTab);
    return true;
}
