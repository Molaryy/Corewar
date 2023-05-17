/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** Pars_header
*/

#include "asm.h"
#include "jb.h"

void clean_array(char **array)
{
    for (int i = 0; array[i]; i++)
        clean_string(array[i]);
}

int check_header(char **parser, file_t *file, size_t status)
{
    clean_array(parser);
    if (is_name(parser[0]))
        file->header->name = my_strdup(parser[1]);
    if (is_description(parser[0]))
        file->header->description = my_strdup(parser[1]);
    if (!check_nb_arg(parser, 2))
        status = FAILURE;
    return status;
}

int parse_header(file_t *file, char *filepath)
{
    char **parser = NULL;
    size_t status = 0;

    file->origin_file = get_file(filepath);
    clean_array(file->origin_file);
    for (int i = 0; file->origin_file[i]; i++) {
        if (file->origin_file[i][0] != '.' && file->origin_file[i][0] != '#')
            break;
        if (!is_commentary(file->origin_file[i])) {
            parser = str_to_array_separator(file->origin_file[i], "\"");
            status = check_header(parser, file, status);
            free_array_str(parser);
        }
        if (status == FAILURE)
            return status;
    }
    if (!file->header->name || !file->header->description)
        status = FAILURE;
    return status;
}
