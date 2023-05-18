/*
** EPITECH PROJECT, 2023
** PROJECT
** File description:
** check_type_arguments
*/

#include "jb.h"
#include "asm.h"
#include "parser.h"

static size_t get_type(char c, char *name)
{
    size_t valueToReturn = 0;
    char *instructions[] = {"live", "fork", "zjump", NULL};

    switch (c) {
        case 'r': valueToReturn = 0; break;
        case '%': valueToReturn = 2; break;
        default: valueToReturn = 2; break;
    }
    for (size_t i = 0; instructions[i]; i++) {
        if (my_strcmp(name, instructions[i]))
            valueToReturn = 1;
    }
    if (my_strcmp(name, "ld") && valueToReturn != 0)
        valueToReturn = 1;
    if (my_strcmp(name, "lld") && valueToReturn != 0)
        valueToReturn = 1;
    return valueToReturn;
}

static bool check_one_arg(parser_t *pars, size_t type, char *name)
{
    for (size_t i = 0; i < NB_INSTRIUCTIONS; i++){
        if (!my_strcmp(pars[i].name, name))
            continue;
        if (pars[i].p1 == type)
            return true;
    }
    return false;
}

static bool check_two_args(parser_t *pars, size_t type, size_t j, char *name)
{
    for (size_t i = 0; i < NB_INSTRIUCTIONS; i++){
        if (!my_strcmp(pars[i].name, name))
            continue;
        if (pars[i].p1 == type && j == 0)
            return true;
        if (pars[i].p2 == type && j == 1)
            return true;
    }
    return false;
}

static bool check_three_args(parser_t *pars, size_t type, size_t j, char *name)
{
    for (size_t i = 0; i < NB_INSTRIUCTIONS; i++){
        if (!my_strcmp(pars[i].name, name))
            continue;
        if (pars[i].p1 == type && j == 0)
            return true;
        if (pars[i].p2 == type && j == 1)
            return true;
        if (pars[i].p3 == type && j == 2)
            return true;
    }
    return false;
}

bool check_type_arguments(char **line, parser_t *pars, size_t start)
{
    size_t type = 0;
    size_t nbParams = 0;
    bool checkArg = false;

    if (!line || !pars)
        return false;
    for (size_t i = start + 1, j = 0; line[i] ; i++, j++) {
        nbParams = get_number_params(line[start], pars);
        type = get_type(line[i][0], line[start]);
        switch (nbParams) {
            case 1: checkArg = check_one_arg(pars, type, line[start]); break;
            case 2: checkArg = check_two_args(pars, type, j, line[start]);
                break;
            case 3: checkArg = check_three_args(pars, type, j, line[start]);
                break;
        }
        if (!checkArg)
            return false;
    }
    return true;
}
