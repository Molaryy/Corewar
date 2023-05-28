/*
** EPITECH PROJECT, 2023
** corewar/src/champion/stack.c
** File description:
** all functions related to stack inside the champion entity
*/

#include "core.h"

static char *parse_name_stack_create(char *file_content, unsigned int file_size)
{
    char *res = malloc(PROG_NAME_LENGTH);

    for (unsigned int i = 0; i < PROG_NAME_LENGTH && i < file_size; i++) {
        res[i] = file_content[i];
    }
    return res;
}

static unsigned char *code_stack_create(char *file_content,
    unsigned int file_size)
{
    unsigned int i = 0;
    unsigned char *code = malloc(sizeof(unsigned char) * (file_size -
        (PROG_NAME_LENGTH + COMMENT_LENGTH) + 16));

    for (unsigned int j = ((PROG_NAME_LENGTH + COMMENT_LENGTH) + 16)
        ; j < file_size; j++, i++) {
        code[i] = (unsigned char) file_content[j];
    }
    return code;
}

stack_t stack_create(champion_t *champ, char *filename)
{
    stack_t stack = {0};
    file_t file = get_file_content(filename);
    char *tmp;

    if (file.file_size == (size_t) -1) {
        champ->name = my_strdup("ERROR");
        stack.code = malloc(sizeof(unsigned char));
        return stack;
    }
    tmp = parse_name_stack_create(file.file_content, file.file_size);
    champ->name = trim_str(tmp, PROG_NAME_LENGTH);
    stack.code_size = (unsigned int) file.file_size - ((PROG_NAME_LENGTH +
        COMMENT_LENGTH) + 16);
    stack.code = code_stack_create(file.file_content, (unsigned int)
        file.file_size);
    free_2(file.file_content, tmp);
    return stack;
}
