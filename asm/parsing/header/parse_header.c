/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** Pars_header
*/

#include "asm.h"
#include "jb.h"

static bool get_header(char *line, file_t *file)
{
    char **pars = NULL;
    char **args = NULL;

    if (!(pars = str_to_array_separator(line, "\"")))
        return false;
    if (!(args = str_to_array_separator(line, " \t")))
        return false;
    if (!pars[1])
        return false;
    if (my_strcmp(args[0], ".name")) {
        if (my_strlen(pars[1]) > 129)
            return false;
        q_strcpy(file->header->name, pars[1]);
    }
    if (my_strcmp(args[0], ".comment")){
        if (my_strlen(pars[1]) > 2049)
            return false;
        q_strcpy(file->header->description, pars[1]);
    }
    return true;
}

extern int parse_header(file_t *file, char *filepath)
{
    size_t status = 0;

    file->origin_file = get_file(filepath);
    for (size_t i = 0; file->origin_file[i]; i++) {
        file->origin_file[i] = remove_str_beg_separator(file->origin_file[i],
        " \t");
        if (file->origin_file[i][0] == '#')
            continue;
        if (file->origin_file[i][0] == '.' &&
        get_header(file->origin_file[i], file))
            continue;
        if (file->origin_file[i][0] == '.' &&
        !get_header(file->origin_file[i], file))
                return FAILURE;
        break;
    }
    return status;
}
