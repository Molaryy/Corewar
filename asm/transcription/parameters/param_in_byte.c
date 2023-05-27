/*
** EPITECH PROJECT, 2023
** param in byte
** File description:
** fs
*/

#include "asm.h"

extern void print_bytes_to_file(const parambyte_t* paramByte, int fd)
{
    if (fd == -1)
        exit(EXIT_FAILURE);
    write(fd, paramByte->bytes, sizeof(unsigned char) * paramByte->size);
}

extern void print_byte(parambyte_t **paramBytes, int i)
{
    for (size_t j = 0; j < paramBytes[i]->size; j++)
        my_printf("0x%h ", paramBytes[i]->bytes[j]);
    my_printf("\n");
}

extern void parameters_in_byte(file_t *file, char *instruction, char **params,
                        int k)
{
    parambyte_t *paramBytes[file->champ[k].nbParams];
    bool is_index = get_instruction_index(find_index(instruction),
                    paramBytes, file, k);
    if (!is_index) {
        for (size_t i = 0; i < file->champ[k].nbParams; i++) {
            paramBytes[i] = create_param_byte(params[i], file, i);
            print_bytes_to_file(paramBytes[i], file->fd);
        }
    }
}
