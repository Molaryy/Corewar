/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** coding btye
*/

#include "asm.h"

void coding_byte(char **params, size_t nbParams)
{
    if (nbParams < 1)
        params[0] = NULL;
    if (nbParams < 2)
        params[1] = NULL;
    if (nbParams < 3)
        params[2] = NULL;

    unsigned char byte = create_byte(params[0], params[1], params[2]);

    printf("Byte value: 0x%02X\n", byte);
    print_bits(byte);
}
