/*
** EPITECH PROJECT, 2022
** my_put_science.c
** File description:
** put nbr float in scentifique
*/

#include <stdarg.h>

#include "flags.h"

int my_put_float2(double nb, int *char_count, specifier_t specifier);
int my_putchar_printf(char c, int *char_count);
int my_compute_power_rec(int nb, int p);
void my_put_nbr_printf_ll(long long int n, int *char_count);

int nbr_puissance(double nb)
{
    int i = 0;
    double save = nb;

    if (save >= 1 || save <= -1) {
        while (nb > 1 || nb < -1) {
            nb /= 10;
            i++;
        }
    }
    if ( save < 1 && save > -1) {
        while ((int)nb % 10 == 0) {
            nb *= 10;
            i--;
        }
    }
    return (i);
}

void my_put_power(int i, int *char_count)
{
    if (i >= 0) {
        my_putchar_printf('+', char_count);
    } else {
        my_putchar_printf('-', char_count);
    }
    if (i < 10 && i > -10)
        my_putchar_printf('0', char_count);
    if (i < 0)
        i *= -1;
    my_put_nbr_printf_ll(i, char_count);
}

double my_put_neg_e(double nb, int *char_count)
{
    if (nb < 0) {
        nb = nb * (double)-1;
        my_putchar_printf('-', char_count);
    }
    return (nb);
}

int my_put_science(va_list arguments, int *char_count, specifier_t specifier)
{
    double nb = va_arg(arguments, double);
    char flag = specifier.conversion_specifier;
    int precision = specifier.precision;
    specifier.min_width = 0;
    int i;

    nb = my_put_neg_e(nb, char_count);
    if (nb >= 1) {
        i = nbr_puissance(nb) - 1;
        nb = nb / my_compute_power_rec(10, i);
    } else {
        i = nbr_puissance(nb);
        nb = nb * my_compute_power_rec(10, i * -1);
    }
    my_put_float2(nb, char_count, specifier);
    my_putchar_printf(flag, char_count);
    my_put_power(i, char_count);
    return (0);
}
