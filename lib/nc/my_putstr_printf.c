/*
** EPITECH PROJECT, 2022
** my_putstr_printf
** File description:
** This is a custom function of my_putstr for my_printf
*/

#include <stdlib.h>
#include <stdarg.h>

#include "str_linked_list.h"
#include "flags.h"

int my_putchar_printf(char c, int *count);
int my_strlen(char const *str);
int my_putchar_printf(const char c, int *count);

void add_padding_right(specifier_t specifier, int *count, char *str)
{
    int min_width = specifier.min_width;
    int str_width = my_strlen(str);

    if (str_width < min_width && specifier.flag == '-') {
        for (int j = 0; j < min_width - str_width; j++)
            my_putchar_printf(' ', count);
    }
}

int my_putstr_printf(va_list arguments, int *count, specifier_t specifier)
{
    char *str = va_arg(arguments, char*);
    unsigned int i = 0;
    int min_width = specifier.min_width;
    int str_width = my_strlen(str);

    if (str_width < min_width && specifier.flag != '-') {
        for (int j = 0; j < min_width - str_width; j++)
            my_putchar_printf(' ', count);
    }
    while (str[i] != '\0') {
        my_putchar_printf(str[i], count);
        i++;
    }
    add_padding_right(specifier, count, str);
    return 0;
}
