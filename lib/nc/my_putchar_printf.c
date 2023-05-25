/*
** EPITECH PROJECT, 2022
** my_putchar_printf
** File description:
** This is the custom function of my_putchar for my_printf
*/

#include <unistd.h>

int my_putchar_printf(const char c, int *count)
{
    int res;

    res = write(1, &c, 1);
    if (res == -1)
        return -1;
    (*count)++;
    return 1;
}
