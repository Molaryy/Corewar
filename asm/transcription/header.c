/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** header.c
*/

#include "asm.h"

void write_header(file_t *file, char *filename)
{
    int data = 0xea83f3;
    unsigned char header[PROG_NAME_LENGTH + COMMENT_LENGTH] = {0};

    for (size_t i = 0; i < sizeof(data); i++) {
        header[i] = (data >> (8 * (sizeof(data) - 1 - i)));
    }
    for (size_t j = 0; j < PROG_NAME_LENGTH; j++) {
        header[sizeof(data) + j] = file->header->name[j];
    }
    for (size_t k = 0; k < COMMENT_LENGTH; k++) {
        header[sizeof(data) + PROG_NAME_LENGTH + k] =
                            file->header->description[k];
    }
    file->fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    write(file->fd, header, sizeof(header));
}
