/*
** EPITECH PROJECT, 2022
** flag%g.c
** File description:
** make a choice between %f and %e
*/

#include <stdarg.h>
#include "flags.h"

int my_put_float2(double nb, int *char_count, specifier_t specifier);
int my_put_science2(double nb, int *char_count, specifier_t specifier);
int my_putchar_printf(const char c, int *count);
int nbr_puissance(double nb);
void my_put_nbr_printf_ll(long long int n, int *char_count);
void padding_left_s_c(int str_width, specifier_t specifier, int is_neg,
    int *char_count);
void padding_right_s_c(int str_width, specifier_t specifier, int is_neg,
    int *char_count);
void decide_e_f(int i, double nb, int *count_char, specifier_t specifier);

int find_precision2(int n, int count)
{
    if (n + count > 6)
        n -= (n + count) - 6;
    return (n);
}

int find_precision(double nb)
{
    int i = 1;
    int n = 0;
    int count = 0;
    int save = (int)nb;

    while (save > 0) {
        save = save / 10;
        count++;
    }
    for (i; i < 7; i++) {
        nb *= 10;
        if ((int)nb % 10 != 0) {
            n = i;
        }
    }
    n = find_precision2(n, count);
    return (n);
}

int cut(specifier_t *specifier, double nb)
{
    if ( (*specifier).conversion_specifier == 'G')
        (*specifier).conversion_specifier = 'E';
    else
        (*specifier).conversion_specifier = 'e';
    return nbr_puissance(nb);
}

int flag_g(va_list arguments, int *count_char, specifier_t specifier)
{
    double nb = va_arg(arguments, double);
    int i;
    int precision = specifier.precision;
    int find_preci = find_precision(nb < 0 ? -nb : nb);
    double pos_nb = nb < 0 ? -nb : nb;

    if (nb == 0.0) {
        my_putchar_printf('0', count_char);
        return 0;
    }
    i = cut(&specifier, nb);
    decide_e_f(i, nb, count_char, specifier);
    return 0;
}
