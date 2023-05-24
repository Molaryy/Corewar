/*
** EPITECH PROJECT, 2023
** corewar/corewar/src/parser/parser.c
** File description:
** parser function for the executable of the vm for corewar
*/

#include "core.h"

#include <stdio.h>

champion_t champion_create(int prog_nbr, int loaded_addr, char *filename)
{
    champion_t champ = {0};

    champ.filename = filename;
    champ.prog_nbr = prog_nbr;
    champ.loaded_addr = loaded_addr;
    champ.stack = stack_create(&champ, filename);
    return champ;
}

char *parse_name_stack_create(char *file_content, unsigned int file_size)
{
    char *res = (char *) malloc(PROG_NAME_LENGTH);

    for (unsigned int i = 0; i < PROG_NAME_LENGTH && i < file_size; i++) {
        res[i] = file_content[i];
    }
    return res;
}

void parse_stack_create(champion_t *champ, stack_t *stack, char *file_content,
    unsigned int file_size)
{
    unsigned int i = 0;
    char *code = malloc(sizeof(unsigned char) * (file_size - (PROG_NAME_LENGTH
        + COMMENT_LENGTH) + 16));

    for (unsigned int j = (PROG_NAME_LENGTH + COMMENT_LENGTH) + 16; j <
        file_size; j++) {

    }
}

stack_t stack_create(champion_t *champ, char *filename)
{
    stack_t stack = {0};
    char *file_content = get_file_content(filename);
    size_t file_size = get_file_size(filename);
    char *tmp;

    if (file_size == (size_t) -1) {
        exit(84);
    }
    tmp = parse_name_stack_create(file_content, file_size);
    champ->name = trim_str(tmp, PROG_NAME_LENGTH);
    free(tmp);
    parse_stack_create(champ, &stack, file_content, (unsigned int) file_size);
    return stack;
}
