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

parser_t *init_parser_reference(char *filepath)
{
    char **parsTab = get_file(filepath);
    parser_t *parser = NULL;
    size_t len = count_tab(parsTab);

    if (!parsTab || len != NB_INSTRIUCTIONS)
        return NULL;
    parser = malloc(sizeof(parser_t) *(len));
    my_printf("len = %d", len);
    free_array_str(parsTab);
    return parser;
}
