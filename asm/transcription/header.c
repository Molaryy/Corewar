/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** header.c
*/

#include "asm.h"

void write_header(file_t *file, char *filename)
{
    unsigned char data[] = {0x00, 0xea, 0x83, 0xf3};

    for (size_t i = 0; i < sizeof(data); i++) {
        file->combinedDataHeader[i] = data[i];
    }
    for (size_t j = 0; j < PROG_NAME_LENGTH; j++) {
        file->combinedDataHeader[sizeof(data) + j] = file->header->name[j];
    }
    for (size_t k = 0; k < COMMENT_LENGTH; k++) {
        file->combinedDataHeader[sizeof(data) + PROG_NAME_LENGTH + k] =
                file->header->description[k];
    }
    file->fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    write(file->fd, file->combinedDataHeader, sizeof(file->combinedDataHeader));
}
