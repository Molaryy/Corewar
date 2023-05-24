/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** header.c
*/

#include "asm.h"

void get_size_each_argument(file_t *file, int i, int j)
{
    if (!file->champ[i].isIndex[j]) {
        if (file->champ[i].params[j][0] == 'r') {
            printf("inst -> [%s] register -> %s\n", file->champ[i].paramName,
                                            file->champ[i].params[j]);
            file->header->prog_size++;
        } else if (file->champ[i].params[j][0] == '%') {
            file->header->prog_size += 4;
            printf("inst -> [%s] direct -> %s\n", file->champ[i].paramName,
                                            file->champ[i].params[j]);
        } else {
            file->header->prog_size += 2;
            printf("inst -> [%s] indirect -> %s\n", file->champ[i].paramName,
                                            file->champ[i].params[j]);
        }
    } else {
        file->header->prog_size += 2;
        printf("inst -> [%s] index -> %s\n", file->champ[i].paramName,
                    file->champ[i].params[j]);
    }
}

void write_header(file_t *file, char *filename)
{
    file->header->magic = htobe32(COREWAR_EXEC_MAGIC);
    file->header->prog_size = 0;
    for (int i = 0; i != file->nbLinesBody; i++) {
        file->header->prog_size++;
        if (file->champ[i].nbParams > 1)
            file->header->prog_size++;
        if (file->champ[i].params == NULL)
            continue;
        for (int j = 0; file->champ[i].params[j]; j++) {
            get_size_each_argument(file, i, j);
        }
    }
    my_printf("prog_size -> %d\n", file->header->prog_size);
    file->fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    write(file->fd, file->header, sizeof(header_t));
}
