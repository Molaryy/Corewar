/*
** EPITECH PROJECT, 2022
** my_pointers_hexa.c
** File description:
** put address of pointers in hexa
*/

#include "flags.h"
#include <stdarg.h>
#include <stddef.h>

int my_put_base_printf2(size_t n, char *base, int *count);
int my_putstr_printf_inte(char const *str, int *count);
unsigned int my_log16(unsigned int n);
int my_putchar_printf(const char c, int *count);

void padding_left_pointer(size_t nb, int *char_count, specifier_t specifier)
{
    int width = 12 + 2;

    width = width - 2 < specifier.precision ?
        specifier.precision + 2 : width + 2;
    if (specifier.min_width > width &&
        specifier.flag != '0' && specifier.flag != '-') {
        for (int i = 0; i < (specifier.min_width - width); i++)
            my_putchar_printf(' ', char_count);
    }
}

void padding_left_pointer_after(size_t nb, int *char_count,
    specifier_t specifier)
{
    int width = 12;

    if (specifier.precision > width) {
        for (int i = 0; i < (specifier.precision - width); i++)
            my_putchar_printf('0', char_count);
    }
}

void padding_right_pointer(size_t nb, int *char_count, specifier_t specifier)
{
    int width = 12 + 2;

    width = width - 2 < specifier.precision ? specifier.precision + 2 :
        width + 2;
    if (specifier.min_width > width &&
        specifier.flag != '0' && specifier.flag == '-') {
        for (int i = 0; i < (specifier.min_width - width); i++)
            my_putchar_printf(' ', char_count);
    }
}

int my_pointers_hexa(va_list arguments, int *char_count, specifier_t specifier)
{
    long unsigned int nb = va_arg(arguments, long unsigned int);

    padding_left_pointer(nb, char_count, specifier);
    my_putstr_printf_inte("0x", char_count);
    padding_left_pointer_after(nb, char_count, specifier);
    my_put_base_printf2(nb, "0123456789abcdef", char_count);
    padding_right_pointer(nb, char_count, specifier);
    return 0;
}
