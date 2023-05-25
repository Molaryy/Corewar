/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** header.c
*/

#include "asm.h"

void int_to_hex(int num, int32_t *hexValue)
{
    unsigned char *hex_arr = malloc(sizeof(int));
    unsigned char *reversed_hex_arr;

    if (hex_arr == NULL)
        return;
    for (size_t i = 0; i < sizeof(int); i++)
        hex_arr[sizeof(int) - 1 - i] = (num >> (8 * i));
    reversed_hex_arr = malloc(sizeof(int));
    if (reversed_hex_arr == NULL) {
        free(hex_arr);
        return;
    }
    for (size_t i = 0; i < sizeof(int); i++)
        reversed_hex_arr[i] = hex_arr[sizeof(int) - 1 - i];
    *hexValue = *(int32_t*)reversed_hex_arr;
    free(hex_arr);
    free(reversed_hex_arr);
}

void check_parameter(file_t *file, int i, int j)
{
    if (file->champ[i].params[j][0] == 'r') {
        file->header->prog_size++;
    } else if (file->champ[i].params[j][0] == '%') {
        file->header->prog_size += 4;
    } else {
        file->header->prog_size += 2;
    }
}

void get_size_each_argument(file_t *file, int i, int j)
{
    if (!file->champ[i].isIndex[j]) {
        check_parameter(file, i, j);
    } else {
        file->header->prog_size += 2;
    }
}

extern bool starting_prog_size(file_t *file, int i)
{
    file->header->prog_size++;
    if (file->champ[i].nbParams > 1)
        file->header->prog_size++;
    if (file->champ[i].params == NULL)
        return true;
    for (int j = 0; file->champ[i].params[j]; j++) {
            get_size_each_argument(file, i, j);
    }
    return false;
}

void write_header(file_t *file, char *filename)
{
    int32_t hexa_prog_size;

    file->header->magic = htobe32(COREWAR_EXEC_MAGIC);
    file->header->prog_size = 0;
    for (size_t i = 0; i != file->nbLinesBody; i++) {
        if (file->champ[i].paramName && starting_prog_size(file, i))
            continue;
    }
    file->fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    write(file->fd, file->header, sizeof(header_t));
}
