/*
** EPITECH PROJECT, 2022
** my_convert_hexa.c
** File description:
** convert nbr in haxa
*/

#include "flags.h"
#include <stdarg.h>

int my_put_base_printf(long long int n, char * base, int *count);
int my_log8(long long int nb);
int my_putchar_printf(const char c, int *count);
int my_putstr_printf_inte(char const *str, int *char_count);

void padding_left_octal(long long int nb, int *char_count,
    specifier_t specifier)
{
    int width = my_log8(nb);
    int code = specifier.flag == '#' ? 2 : 0;
    char padding_char = specifier.flag == '0' ? '0' : ' ';
    if (specifier.min_width > width + code && specifier.flag != '-') {
        for (int i = 0; i < specifier.min_width - (width + code); i++)
            my_putchar_printf(padding_char, char_count);
    }
}

void padding_right_octal(long long int nb, int *char_count,
    specifier_t specifier)
{
    int width = my_log8(nb);
    int code = specifier.flag == '#' ? 2 : 0;

    if (specifier.min_width > width + code && specifier.flag == '-') {
        for (int i = 0; i < specifier.min_width - (width + code); i++)
            my_putchar_printf(' ', char_count);
    }
}

int my_convert_octal(va_list arguments, int *char_count, specifier_t specifier)
{
    long long int nb = va_arg(arguments, int);
    char flag = specifier.conversion_specifier;
    int hash = specifier.flag == '#' ? 1 : 0;

    padding_left_octal(nb, char_count, specifier);
    my_put_base_printf(nb, "01234567", char_count);
    padding_right_octal(nb, char_count, specifier);
    return 0;
}
