/*
** EPITECH PROJECT, 2023
** corewar/src/helper/print_bits.c
** File description:
** this will contain the print_bits function
*/
#include "core.h"
#include <stdbool.h>

void print_bits(unsigned char *buffer, int nb_bits, char *comment)
{
    int count = 0;
    int byte_index;
    int bit_index;
    unsigned int bit;

    my_printf("---DISPLAY BITS FOR %s---\n", comment);
    for (int i = 0; i < nb_bits; i++) {
        byte_index = i / 8;
        bit_index = i % 8;
        bit = (buffer[byte_index] >> (7 - bit_index)) & 1;
        my_printf("%d", bit);
        count++;
        if (count == 8) {
            count = 0;
            my_printf(" ");
        }
    }
    my_printf("\n---BITS DISPLAYED FOR %s\n", comment);
}
