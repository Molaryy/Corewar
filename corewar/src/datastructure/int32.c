/*
** EPITECH PROJECT, 2023
** corewar/src/datastructure/int32.c
** File description:
** these are all the function related to the 32bit unsigned integer
*/

#include "core.h"

void set_32uint(long long int value, unsigned char *array)
{
    array[0] = (value >> 24) & 0xFF;
    array[1] = (value >> 16) & 0xFF;
    array[2] = (value >> 8) & 0xFF;
    array[3] = value & 0xFF;
}

long long int get_32uint(const unsigned char *array)
{
    long long int value = 0;

    value |= (array[0] << 24);
    value |= (array[1] << 16);
    value |= (array[2] << 8);
    value |= array[3];
    return value;
}

void disp_32uint_b(const unsigned char *array)
{
    int i = 0;

    for (int i = 0; i < 4; i++)
        my_put_base_printf((long long int) array[i], "01", &i);
}

void disp_32uint_h(const unsigned char *array)
{
    int i = 0;

    for (int i = 0; i < 4; i++)
        my_printf("%08X ", array[i]);
}
