/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** coding btye
*/

#include "asm.h"

void if_indirect_or_not(const char **params, unsigned char *result_byte, int i)
{
    if (INDIRECT_VALUE)
        *result_byte = *result_byte | (0x30 >> (2 * i));
    else
        *result_byte = *result_byte | (0x00 >> (2 * i));
}

unsigned char create_byte(char* param1, char* param2, char* param3)
{
    const char* params[3] = {param1, param2, param3};
    unsigned char result_byte = 0;

    for (int i = 0; i < 3; i++) {
        if (params[i] != NULL) {
            switch (params[i][0]) {
                case REGISTER:
                    result_byte = result_byte | (0x10 >> (2 * i));
                    break;
                case DIRECT_VALUE:
                    result_byte = result_byte | (0x20 >> (2 * i));
                    break;
                default:
                    if_indirect_or_not(params, &result_byte, i);
                    break;
            }
        }
    }
    result_byte = ((result_byte & 0x3F) << 2);
    return result_byte;
}

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
