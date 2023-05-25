/*
** EPITECH PROJECT, 2022
** my_put_nbr_printf
** File description:
** This is the my_put_nbr adapted for my_printf
*/

#include <stdlib.h>
#include <stdarg.h>

#include "str_linked_list.h"
#include "flags.h"

str_ll_t *my_ll_add(str_ll_t *current_node, char ch);
str_ll_t *add_padding_printf(str_ll_t *memory, int min_Width);
int my_put_ll(str_ll_t *head, int *char_count);
int my_putchar_printf(const char c, int *count);
int my_log(unsigned int n, unsigned int base);

void cut_fonction2_unsigned(specifier_t specifier,
    int width, int padding_char, int *char_count)
{
    if (width < specifier.min_width && specifier.flag == '-') {
        for (int i = 0; i < specifier.min_width - width - 1; i++)
            my_putchar_printf(padding_char, char_count);
    }
}

void cut_fonction_unsigned(specifier_t specifier, int is_neg, int *char_count)
{
    if (is_neg == 1)
        my_putchar_printf('-', char_count);
    if (specifier.flag == '+' && is_neg == 0)
        my_putchar_printf('+', char_count);
}

void frec_printf_unsigned(unsigned int i, int *char_count)
{
    if (i > 0) {
        frec_printf_unsigned(i / 10, char_count);
        my_putchar_printf(i % 10 + '0', char_count);
    } else {
        return;
    }
}

int my_put_nbr_printf_unsigned(va_list arguments, int *char_count,
    specifier_t specifier)
{
    unsigned int n = va_arg(arguments, int);
    int width = 0;
    int is_neg = n < 0 ? 1 : 0;
    char padding_char = specifier.flag == '0' ? '0' : ' ';

    width += my_log(n, 10);
    if (n == 0) {
        my_putchar_printf('0', char_count);
        return 0;
    }
    if (width < specifier.min_width && specifier.flag != '-') {
        for (int i = 0; i < specifier.min_width - width - 1; i++)
            my_putchar_printf(padding_char, char_count);
    }
    cut_fonction_unsigned(specifier, is_neg, char_count);
    frec_printf_unsigned(n, char_count);
    cut_fonction2_unsigned(specifier, width, padding_char, char_count);
    return 0;
}
