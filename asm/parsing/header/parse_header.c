/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** Pars_header
*/

#include "asm.h"
#include "jb.h"

static void count_header(file_t *file, char *line)
{
    if (my_strcmp(line, ".name"))
        file->nbName += 1;
    if (my_strcmp(line, ".comment"))
        file->nbComment += 1;
}

static bool get_header(char *line, file_t *file, char **pars)
{
    char **args = NULL;

    if (!(args = str_to_array_separator(line, " \t")))
        return false;
    count_header(file, args[0]);
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
    char **pars = NULL;

    file->origin_file = get_file(filepath);
    for (size_t i = 0; file->origin_file[i]; i++) {
        file->origin_file[i] = remove_str_beg_separator(file->origin_file[i],
        " \t");
        if (file->origin_file[i][0] == '#')
            continue;
        if (!(pars = str_to_array_separator(file->origin_file[i], "\"")))
            return false;
        if (file->origin_file[i][0] == '.' &&
        get_header(file->origin_file[i], file, pars))
            continue;
        if (file->origin_file[i][0] == '.' &&
        !get_header(file->origin_file[i], file, pars))
                return FAILURE;
        break;
    }
    return status;
}
