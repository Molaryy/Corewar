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
int nbr_puissance(double nb);
void my_put_power(int i, int *char_count);
void my_put_neg_e(double nb, int *char_count);

int my_put_science2(double nb, int *char_count, specifier_t specifier)
{
    char flag = specifier.conversion_specifier;
    int precision = specifier.precision;
    specifier.min_width = 0;
    int i;

    my_put_neg_e(nb, char_count);
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
