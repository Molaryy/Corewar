/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** write into a file
*/

#include "asm.h"

static void write_bytes_to_fd(file_t *file, size_t size)
{
    if (file->fd == -1)
        exit(FAILURE);
    write(file->fd, file->ins_bytes->byte, size);
}

extern void infinit_loop(file_t *file, int i)
{
    if (file->champ[i].nbParams > 1)
        file->ins_bytes->byte = malloc(sizeof(unsigned char) * 2);
    else
        file->ins_bytes->byte = malloc(sizeof(unsigned char));
    file->ins_bytes->byte[0] = instruction_code(file->champ[i].paramName, file);
    if (file->champ[i].nbParams > 1)
        file->ins_bytes->byte[1] = coding_byte(file->champ[i].params,
                                    file->champ[i].nbParams, file);
    if (file->champ[i].nbParams > 1)
        write_bytes_to_fd(file, 2);
    else
        write_bytes_to_fd(file, 1);
    parameters_in_byte(file, file->champ[i].paramName,
        file->champ[i].params, file->champ[i].nbParams);
}

extern void get_byte_and_write(char *filename, file_t *file)
{
    write_header(file, filename);
    file->ins_bytes = malloc(sizeof(instruc_byte_t));

    label_find(file);
    for (size_t i = 0; i != file->nbLinesBody; i++) {
        if (file->champ[i].paramName != NULL) {
            my_printf("size -> %d\n", file->offset);
            infinit_loop(file, i);
        }
    }
}
