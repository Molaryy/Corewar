/*
** EPITECH PROJECT, 2023
** corewar/src/datastrucure/int16.c
** File description:
** int16 man
*/

#include "core.h"

void set_16int(short int value, unsigned char *array)
{
    array[0] = (value >> 8) & 0xFF;
    array[1] = value & 0xFF;
}

short int get_16int(const unsigned char *array)
{
    short int value = 0;

    value |= (array[0] << 8);
    value |= array[1];
    return value;
}
