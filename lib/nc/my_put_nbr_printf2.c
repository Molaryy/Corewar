/*
** EPITECH PROJECT, 2022
** my_printf put nbr simple
** File description:
** this includes the char count var
*/

#include <stdlib.h>
#include <stdarg.h>

#include "str_linked_list.h"
#include "flags.h"

int my_putchar_printf(const char c, int *count);

void frec_printf2(int n, int *char_count)
{
    if (n != 0) {
        frec_printf2(n / 10, char_count);
        my_putchar_printf(n % 10 + '0', char_count);
    } else {
        return;
    }
}

void my_put_nbr_printf2(int n, int *char_count)
{
    if (n < 0) {
        my_putchar_printf('-', char_count);
        n *= -1;
    }
    if (n == 0) {
        my_putchar_printf('0', char_count);
        return;
    }
    frec_printf2(n, char_count);
}

void cut_fonction3(specifier_t specifier,
    int width, int padding_char, int *char_count)
{
    if (width < specifier.min_width && specifier.flag != '-') {
        for (int i = 0; i < specifier.min_width - width - 1; i++)
            my_putchar_printf(padding_char, char_count);
    }
}
