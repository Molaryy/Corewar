/*
** EPITECH PROJECT, 2023
** PROJECT
** File description:
** check_nb_arguments
*/

#include "jb.h"
#include "asm.h"
#include "parser.h"

static bool instruction_exists(char **tab, parser_t *pars, size_t *start)
{
    char *instruction = NULL;

    if (tab[0][my_strlen(tab[0]) - 1] == ':'){
        instruction = tab[1];
        *start = 1;
    } else {
        instruction = tab[0];
        *start = 0;
    }
    if (instruction == NULL)
        return false;
    for (size_t i = 0; i < NB_INSTRIUCTIONS; i++) {
        if (my_strcmp(pars[i].name, instruction))
            return true;
    }
    return false;
}

static size_t get_number_params(char *instruction, parser_t *pars)
{
    if (!instruction)
        return 0;
    for (size_t i = 0; i < NB_INSTRIUCTIONS ; i++) {
        if (my_strcmp(instruction, pars[i].name))
            return pars[i].nb_params;
    }
    return 0;
}

static bool count_params(char *line, parser_t *pars)
{
    char **tab = str_to_array_separator(line, " ,");
    size_t start = 0;
    size_t len = 0;
    size_t nbParams = 0;

    if (!tab)
        return false;
    if (!instruction_exists(tab, pars, &start))
        return false;
    for (size_t i = start; tab[i]; i++)
        len++;
    nbParams = get_number_params(tab[start], pars);
    if (nbParams != (len -1)){
        free_array_str(tab);
        return false;
    }
    if (!check_type_arguments(tab, pars))
        return false;
    free_array_str(tab);
    return true;
}

bool check_instruction_number_arguments(body_t *body, parser_t *pars)
{
    if (!body || !pars)
        return false;
    for (size_t i = 0; body->bodyArray[i] ; i++) {
        if (!count_params(body->bodyArray[i], pars))
            return false;
    }
    return true;
}
