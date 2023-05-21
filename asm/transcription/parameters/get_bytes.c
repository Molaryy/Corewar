/*
** EPITECH PROJECT, 2023
** getbyte
** File description:
** gfdf
*/

#include "asm.h"

extern unsigned char* get_register_bytes(unsigned int value, parambyte_t *paramByte)
{
    unsigned char* bytes = malloc(sizeof(unsigned char));

    if (bytes == NULL)
        exit(FAILURE);
    *bytes = (unsigned char)value;
    paramByte->size = sizeof(unsigned char);
    return bytes;
}

extern unsigned char* get_direct_bytes(unsigned int value, parambyte_t *paramByte)
{
    unsigned char* bytes = NULL;

    bytes = malloc(sizeof(unsigned int));
    if (bytes == NULL) {
        printf("Erreur d'allocation mémoire.\n");
        exit(EXIT_FAILURE);
    }
    for (int i = sizeof(unsigned int) - 1; i >= 0; i--) {
        bytes[i] = (unsigned char)value;
        value >>= 8;
    }
    paramByte->size = sizeof(unsigned int);
    return bytes;
}

extern unsigned char* get_indirect_bytes(unsigned int value, parambyte_t *paramByte)
{
    unsigned char* bytes = NULL;

    bytes = malloc(sizeof(unsigned short));
    if (bytes == NULL) {
        printf("Erreur d'allocation mémoire.\n");
        exit(EXIT_FAILURE);
    }
    for (int i = sizeof(unsigned short) - 1; i >= 0; i--) {
        bytes[i] = (unsigned char)value;
        value >>= 8;
    }
    paramByte->size = sizeof(unsigned short);
    return bytes;
}
