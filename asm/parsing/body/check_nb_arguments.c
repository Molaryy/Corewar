/*
** EPITECH PROJECT, 2023
** PROJECT
** File description:
** check_nb_arguments
*/

#include "jb.h"
#include "asm.h"
#include "parser.h"

static bool instruction_exists(char **tab, parser_t *pars)
{
    char *instruction = NULL;

    if (tab[0][my_strlen(tab[0]) - 1] == ':')
        instruction = tab[1];
    else
        instruction = tab[0];
    if (instruction == NULL)
        return false;
    for (size_t i = 0; i < NB_INSTRIUCTIONS; i++) {
        if (my_strcmp(pars[i].name, instruction))
            return true;
    }
    return false;
}

static size_t count_params(char *line, parser_t *pars)
{
    char **tab = str_to_array_separator(line, " ,");

    if (!tab)
        return 0;
    if (!instruction_exists(tab, pars))
        return 0;
    free_array_str(tab);
    return 0;
}

bool check_instruction_number_arguments(body_t *body, parser_t *pars)
{
    size_t nbArgs = 0;

    for (size_t i = 0; body->bodyArray[i] ; i++) {
        nbArgs = count_params(body->bodyArray[i], pars);
    }
    return true;
}
