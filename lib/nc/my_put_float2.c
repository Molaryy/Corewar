/*
** EPITECH PROJECT, 2022
** my_put_float.c
** File description:
** put float
*/

#include <stdarg.h>
#include "flags.h"

int my_putchar_printf(char c, int *char_count);
int my_put_nbr_printf2(int n, int *char_count);
unsigned int my_log(unsigned int n, unsigned int base);
int my_compute_power_rec(int nb, int power);
void put_after_point(double nb, int *char_count,
    int precision, int is_precision);
double nb_is_neg(double nb);

void padding_left_float2(double nb, int *char_count, specifier_t specifier)
{
    int nb_int = (int)nb;
    int precision = specifier.precision;
    char padding_char = specifier.flag == '0' ? '0' : ' ';
    int is_neg = nb < 0 ? 1 : 0;
    int is_precision = specifier.precision <= 0 ? 0 : 1;
    int flag_plus = specifier.flag == '+' ? -1 : 0;

    if (specifier.min_width > my_log(nb_int, 10) +
        precision + is_precision + is_neg - flag_plus &&
        specifier.flag != '-') {
        for (int i = 0; i < (specifier.min_width - (my_log(nb_int, 10)
            + precision + is_precision + is_neg - flag_plus)) - 1; i++)
            my_putchar_printf(padding_char, char_count);
    }
}

void padding_right_float2(double nb, int *char_count, specifier_t specifier)
{
    int nb_int = (int)nb;
    int precision = specifier.precision;
    char padding_char = specifier.flag == '0' ? '0' : ' ';
    int is_neg = nb < 0 ? 1 : 0;
    int is_precision = specifier.precision <= 0 ? 0 : 1;
    int flag_plus = specifier.flag == '+' ? -1 : 0;

    if (specifier.min_width > my_log(nb_int, 10) + precision
        + is_precision + is_neg + flag_plus && specifier.flag == '-') {
        for (int i = 0; i < (specifier.min_width - (my_log(nb_int, 10)
        + precision + is_precision + is_neg + flag_plus)) - 1; i++)
            my_putchar_printf(padding_char, char_count);
    }
}

int my_put_float2(double nb, int *char_count, specifier_t specifier)
{
    int nb_int = (int)nb;
    int precision = specifier.precision;
    char padding_char = specifier.flag == '0' ? '0' : ' ';
    int is_neg = nb < 0 ? 1 : 0;
    int is_precision = specifier.precision <= 0 ? 0 : 1;
    int flag_plus = specifier.flag == '+' ? -1 : 0;

    nb = nb_is_neg(nb);
    nb -= nb_is_neg((double)nb_int);
    padding_left_float2(nb, char_count, specifier);
    if (specifier.flag == '+' && is_neg != 1)
        my_putchar_printf('+', char_count);
    my_put_nbr_printf2(nb_int, char_count);
    put_after_point(nb, char_count, precision, is_precision);
    padding_right_float2(nb, char_count, specifier);
    return 0;
}
