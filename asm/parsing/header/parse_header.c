/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** Pars_header
*/

#include "asm.h"
#include "jb.h"

extern void clean_array(char **array)
{
    for (int i = 0; array[i]; i++)
        clean_string(array[i]);
}

static bool check_header_compenents(char **parser)
{
    size_t countHeader = 0;

    if (!parser || !parser[0])
        return false;
    if (my_strcmp(parser[0], ".name") || my_strcmp(parser[0], ".comment"))
        countHeader++;
    if (countHeader == 0)
        return false;
    return true;
}

extern int check_header(char **parser, file_t *file, size_t status)
{
    clean_array(parser);
    if (!parser[1])
        return FAILURE;
    if (!check_header_compenents(parser))
        return FAILURE;
    if (is_name(parser[0]))
        q_strcpy(file->header->name, parser[1]);
    if (is_description(parser[0]))
        q_strcpy(file->header->description, parser[1]);
    if (!check_nb_arg(parser, 2))
        status = FAILURE;
    return status;
}

extern int parse_header(file_t *file, char *filepath)
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
    my_printf("name -> %s\n", file->header->name);
    return status;
}
