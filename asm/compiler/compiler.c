/*
** EPITECH PROJECT, 2023
** PROJECT
** File description:
** main_compiler.c
*/

#include "jb.h"
#include "asm.h"
#include "parser.h"

static int get_index_label(char **tab)
{
    for (size_t i = 0; tab[i]; i++) {
        if (tab[i][0] == '%' && tab[i][1] == ':')
            return i;
    }
    return (-1);
}

static bool is_label_in_link(char *str, link_t *label)
{
    link_t *tmp = label;
    char *cpy = NULL;

    for (; tmp; tmp = tmp->next) {
        cpy = my_strcpy(tmp->data);
        cpy[my_strlen(cpy) - 1] = '\0';
        if (my_strcmp(cpy, str))
            return true;
    }
    return false;
}

static bool check_if_label_exists(champ_t *champ, link_t *label, size_t len)
{
    char **tab = NULL;
    int index = 0;

    for (size_t i = 0; i < len; i++) {
        tab = champ[i].params;
        index = get_index_label(tab);
        if (index < 0)
            continue;
        if (!is_label_in_link(&tab[index][2], label))
            return false;
    }
    return true;
}

static size_t parsing_compiler(parser_t *parser, file_t *file, char *filepath)
{
    if (!parse_body(file, filepath))
        return FAILURE;
    if (!check_instruction_number_arguments(file->body, parser))
        return FAILURE;
    if (!add_labels_to_link(file->body, file))
        return FAILURE;
    if (!check_if_label_exists(file->champ, file->body->labels, file->nbLinesBody))
        return FAILURE;
    return SUCCESS;
}

extern size_t compiler(char *filepath)
{
    file_t *file = malloc(sizeof(file_t));
    file->body = malloc(sizeof(body_t));
    file->header = malloc(sizeof(header_t));
    parser_t *parser = NULL;

    if (!init_compiler(file, parser))
        return FAILURE;
    if (!detect_file_extension(filepath))
        return FAILURE;
    if (!(parser = init_parser_reference(".instructions.txt")))
        return FAILURE;
    if (parse_header(file, filepath) > 0)
        return FAILURE;
    if (file->nbName == 0 || file->nbName > 1
    || file->nbComment == 0 || file->nbComment > 1)
        return FAILURE;
    if (parsing_compiler(parser, file, filepath) == FAILURE)
        return FAILURE;
    cor_file(filepath, file);
    return SUCCESS;
}
