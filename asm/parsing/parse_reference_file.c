/*
** EPITECH PROJECT, 2023
** PROJECT
** File description:
** parse_txt_file
*/

#include "jb.h"
#include "asm.h"
#include "parser.h"

char **get_file(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char *buffer = NULL;
    char **fileTab = NULL;
    struct stat info;

    if (stat(filepath, &info) == -1)
        return NULL;
    buffer = malloc(sizeof(char) * (info.st_size + 1));
    if (!buffer)
        return NULL;
    buffer[info.st_size] = '\0';
    if (read(fd, buffer, info.st_size) == -1)
        return NULL;
    fileTab = str_to_array_separator(buffer, "\n");
    free(buffer);
    close(fd);
    return fileTab;
}

static parser_t get_params(parser_t pars, char **params)
{
    switch (pars.nb_params) {
        case 1:
            pars.p1 = my_getnbr(params[0]);
            break;
        case 2:
            pars.p1 = my_getnbr(params[0]);
            pars.p2 = my_getnbr(params[1]);
            break;
        case 3:
            pars.p1 = my_getnbr(params[0]);
            pars.p2 = my_getnbr(params[1]);
            pars.p3 = my_getnbr(params[2]);
            break;
    }
    return pars;
}

static bool start_parser_values(parser_t *pars, size_t len, char **file)
{
    char **filePars = NULL;
    char **params = NULL;

    for (size_t i = 0; i < len ; i++) {
        if (!(filePars = str_to_array_separator(file[i], "~")))
            return false;
        pars[i].name = my_strcpy(filePars[0]);
        pars[i].nb_params = my_getnbr(filePars[1]);
        if (!(params = str_to_array_separator(filePars[2], "() ")))
            return false;
        pars[i] = get_params(pars[i], params);
        free_array_str(filePars);
        free_array_str(params);
    }
    return true;
}

parser_t *init_parser_reference(char *filepath)
{
    char **parsTab = get_file(filepath);
    parser_t *parser = NULL;
    size_t len = count_tab(parsTab);

    if (!parsTab || len != NB_INSTRIUCTIONS)
        return NULL;
    parser = malloc(sizeof(parser_t) *(len));
    if (!parser)
        return NULL;
    start_parser_values(parser, len, parsTab);
    for (size_t i = 0 ; i < len ; i++)
        my_printf("%s\n", parser[i].name);
    free_array_str(parsTab);
    return parser;
}
