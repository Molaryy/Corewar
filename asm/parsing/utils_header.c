/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** utils header
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

bool check_nb_arg(char **array, size_t max)
{
    size_t count = 0;

    for (int i = 0; array[i]; i++)
        count++;
    if (count > max)
        return false;
    else
        return true;
}
