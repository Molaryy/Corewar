/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** index files
*/

#include "asm.h"

extern unsigned int get_value(const char* param, int opt)
{
    unsigned int value = 0;

    if (opt == 0)
        value = (param[1] - '0');
    if (opt == 1)
        for (int i = 1; param[i] != '\0'; i++)
            value = (value << 3) + (value << 1) + (param[i] - '0');
    if (opt == 2)
        for (int i = 0; param[i] != '\0'; i++)
            value = (value << 3) + (value << 1) + (param[i] - '0');
    return value;
}

extern unsigned int find_index(char *instruction)
{
    char *instruction_index[] = {
        "zjmp",
        "ldi",
        "sti",
        "fork",
        "lldi",
        "lfork",
        NULL,
    };

    for (int i = 0; instruction_index[i]; i++) {
        if (my_strcmp(instruction, instruction_index[i]))
            return (unsigned int)i;
    }
    return 84;
}

extern void value_sup_4(parambyte_t *paramBytes[], file_t *file,
                    unsigned int value, int k)
{
    if (value == 4) {
        for (int i = 0; i != 3; i++) {
            paramBytes[i] = create_ldi_bytes(file->champ[k].params[i], file,
                                                k);
            print_bytes_to_file(paramBytes[i], file->fd);
        }
    }
    if (value == 5) {
            paramBytes[0] = create_fork_bytes(file->champ[k].params[0],
                            file, k);
            print_bytes_to_file(paramBytes[0], file->fd);
    }
}

extern void value_sup_2(parambyte_t *paramBytes[], file_t *file,
                    unsigned int value, int k)
{
    if (value == 2) {
        for (int i = 0; i != 3; i++) {
            paramBytes[i] = create_sti_bytes(file->champ[k].params[i], file,
                                                k);
            print_bytes_to_file(paramBytes[i], file->fd);
        }
    }
    if (value == 3) {
        paramBytes[0] = create_fork_bytes(file->champ[k].params[0], file, k);
        print_bytes_to_file(paramBytes[0], file->fd);
    }
    value_sup_4(paramBytes, file, value, k);
}

extern int get_instruction_index(unsigned int flags, parambyte_t *paramBytes[],
                            file_t *file, int k)
{
    unsigned int value = flags & 0xFF;

    if (value == 0) {
        paramBytes[0] = create_zjmp_bytes(file->champ[k].params[0], file, k);
        print_bytes_to_file(paramBytes[0], file->fd);
    }
    if (value == 1) {
        for (int i = 0; i != 3; i++) {
            paramBytes[i] = create_ldi_bytes(file->champ[k].params[i], file, k);
            print_bytes_to_file(paramBytes[i], file->fd);
        }
    }
    value_sup_2(paramBytes, file, value, k);
    if (value == 84)
        return false;
    return true;
}
