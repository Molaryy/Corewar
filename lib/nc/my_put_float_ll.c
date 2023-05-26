/*
** EPITECH PROJECT, 2022
** my_put_float.c
** File description:
** put float
*/

#include <stdarg.h>
#include "flags.h"

int my_putchar_printf(char c, int *char_count);
unsigned int my_log(unsigned int n, unsigned int base);
int my_compute_power_rec(int nb, int power);
void my_put_nbr_printf2(int n, int *char_count);
void my_put_nbr_printf_ll(long long int n, int *char_count);

void put_after_point(double nb, int *char_count,
    int precision, int is_precision)
{
    long long int save;
    int save_preci = precision;

    if (precision != 0)
        my_putchar_printf('.', char_count);
    for (int i = 0; (int)nb % 10 == 0 && i < save_preci; i++) {
        nb *= 10;
        if (i != 0)
            my_putchar_printf('0', char_count);
        precision--;
    }
    nb *= my_compute_power_rec(10, precision);
    nb += 0.5;
    save = (long long int)nb;
    my_put_nbr_printf_ll(save, char_count);
}

double nb_is_neg(double nb)
{
    if (nb < 0)
        nb *= -1.0;
    return (nb);
}

void padding_left_float_ll(double nb, int *char_count, specifier_t specifier,
    int is_neg)
{
    int nb_int = (int)nb;
    int precision = specifier.precision;
    char padding_char = specifier.flag == '0' ? '0' : ' ';
    int is_precision = specifier.precision <= 0 ? 0 : 1;
    int flag_plus = specifier.flag == '+' ? -1 : 0;

    if (specifier.min_width > my_log(nb_int, 10) + precision
        + is_precision + is_neg + flag_plus && specifier.flag != '-') {
        for (int i = 0; i < (specifier.min_width - (my_log(nb_int, 10)
        + precision + is_precision + is_neg + flag_plus)) - 1; i++)
            my_putchar_printf(padding_char, char_count);
    }
}

void padding_right_float_ll(double nb, int *char_count, specifier_t specifier,
    int is_neg)
{
    int nb_int = (int)nb;
    int precision = specifier.precision;
    char padding_char = specifier.flag == '0' ? '0' : ' ';
    int is_precision = specifier.precision <= 0 ? 0 : 1;
    int flag_plus = specifier.flag == '+' ? -1 : 0;

    if (specifier.min_width > my_log(nb_int, 10) + precision
        + is_precision + is_neg + flag_plus && specifier.flag == '-') {
        for (int i = 0; i < (specifier.min_width - (my_log(nb_int, 10)
        + precision + is_precision + is_neg + flag_plus)) - 1; i++)
            my_putchar_printf(padding_char, char_count);
    }
}

int my_put_float_ll(va_list arguments, int *char_count, specifier_t specifier)
{
    double nb = va_arg(arguments, double);
    int nb_int = (int)nb;
    int precision = specifier.precision;
    char padding_char = specifier.flag == '0' ? '0' : ' ';
    int is_neg = nb < 0 ? 1 : 0;
    int is_precision = specifier.precision <= 0 ? 0 : 1;
    int flag_plus = specifier.flag == '+' ? -1 : 0;

    nb = nb_is_neg(nb);
    nb -= nb_is_neg((double)nb_int);
    padding_left_float_ll(nb, char_count, specifier, is_neg);
    if (specifier.flag == '+' && is_neg != 1)
        my_putchar_printf('+', char_count);
    my_put_nbr_printf2(nb_int, char_count);
    put_after_point(nb, char_count, precision, is_precision);
    padding_right_float_ll(nb, char_count, specifier, is_neg);
    return 0;
}
