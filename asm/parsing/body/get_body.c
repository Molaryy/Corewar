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

    for (size_t i = 0; file[i]; i++){
        file[i] = remove_str_beg_separator(file[i], " \t");
        file[i] = remove_after_separator(file[i], "#");
    }
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

static void get_label(char **pars, champ_t *champ, size_t i, size_t *start)
{
    if (pars[0][my_strlen(pars[0]) - 1] == ':') {
        champ[i].label = my_strcpy(pars[0]);
        champ[i].paramName = my_strcpy(pars[1]);
        champ[i].index = i;
        *start = 2;
    } else
        champ[i].paramName = my_strcpy(pars[0]);
}

static bool fill_champ(champ_t *champ, size_t len, char **body)
{
    char **pars = NULL;
    size_t start = 1;

    champ = init_champ(champ, len);
    for (size_t i = 0; i < len; i++) {
        start = 1;
        if (!(pars = str_to_array_separator(body[i], "\t ,")))
            return false;
        get_label(pars, champ, i, &start);
        champ[i].nbParams = count_tab(pars) - start;
        check_start(pars[0][my_strlen(pars[0]) - 1], start);
        if (pars[1] != NULL)
            champ[i].params = cpy_tab(pars, start);
        free_array_str(pars);
    }
    check_index(champ, len);
    return true;
}

extern bool parse_body(file_t *file, char *filepath)
{
    size_t len = 0;

    if (!(file->body->bodyArray = get_body(get_file(filepath))))
        return false;
    len = count_tab(file->body->bodyArray);
    file->nbLinesBody = len;
    if (!(file->champ = malloc(sizeof(champ_t) * len)))
        return false;
    fill_champ(file->champ, file->nbLinesBody, file->body->bodyArray);
    print_champion(file->champ, file->nbLinesBody);
    return true;
}
