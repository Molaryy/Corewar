/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** Pars_header
*/

#include "asm.h"
#include "jb.h"

bool is_commentary(char *line)
{
    if (!line)
        return false;
    if (line[0] == COMMENT_CHAR)
        return true;
    else
        return false;
}

bool is_name(char *line)
{
    if (!line)
        return false;
    if (my_strcmp(line, NAME_CMD_STRING))
        return true;
    else 
        return false;
}

bool is_description(char *line)
{
    if (!line)
        return false;
    if (my_strcmp(line, COMMENT_CMD_STRING))
        return true;
    else 
        return false;
}

void clean_array(char **array)
{
    for (int i = 0; array[i]; i++)
        clean_string(array[i]);
}

void parse_header(file_t *file, char *filepath) 
{
    char **parser = NULL;

    file->origin_file = get_file(filepath);
    clean_array(file->origin_file);

    for (int i = 0; file->origin_file[i]; i++) {
        if (file->origin_file[i][0] != '.' && file->origin_file[i][0] != '#')
            break;
        if (!is_commentary(file->origin_file[i])) {
            parser = str_to_array_separator(file->origin_file[i], "\"");
            my_printf("%t", parser);
            //printf("%s\n", file->origin_file[i][0]);
        }
    }
    clean_array(parser);
    free_array_str(parser);
}