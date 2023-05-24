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
    champ.stack = stack_create(filename);
    return champ;
}

char *parse_name_stack_create(char *file_content, unsigned int *i,
    unsigned int file_size)
{
    char *res = (char *) malloc(PROG_NAME_LENGTH);

    for (; *i < PROG_NAME_LENGTH / 8 && *i < file_size; (*i)++) {

    }
}

void parse_stack_create(stack_t *stack, char *file_content, unsigned int
    file_size)
{
    unsigned int i = 0;
    char *code = malloc(sizeof(unsigned char) * (file_size - (PROG_NAME_LENGTH
        + COMMENT_LENGTH) + 16));

    for (unsigned int j = (PROG_NAME_LENGTH + COMMENT_LENGTH) + 16; j <
        file_size; j++)
        write(1, &file_content[j], 1);
    /* stack->name = parse_name_stack_create(filen_content, file_size); */
}

stack_t stack_create(char *filename)
{
    stack_t stack = {0};
    char *file_content = get_file_content(filename);
    size_t file_size = get_file_size(filename);

    if (file_size == (size_t) -1) {
        exit(84);
    }
    parse_stack_create(&stack, file_content, (unsigned int) file_size);
    return stack;
}
