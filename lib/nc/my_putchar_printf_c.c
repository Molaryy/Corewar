/*
** EPITECH PROJECT, 2022
** flag c
** File description:
** This will handle the flag c in its entierity
*/

#include <stdarg.h>

#include "flags.h"

int my_putchar_printf(const char c, int *count);

int my_putchar_printf_c(va_list arguments, int *char_count,
    specifier_t specifier)
{
    char c = va_arg(arguments, int);
    int error = 0;

    if (specifier.min_width > 1 && specifier.flag != '-') {
        for (int i = 0; i < specifier.min_width - 1; i++)
            error = my_putchar_printf(' ', char_count);
    }
    my_putchar_printf((char)c, char_count);
    if (specifier.min_width > 1 && specifier.flag == '-') {
        for (int i = 0; i < specifier.min_width - 1; i++)
            error = my_putchar_printf(' ', char_count);
    }
    return error;
}
