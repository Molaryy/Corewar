/*
** EPITECH PROJECT, 2022
** flag g
** File description:
** second find for flag g
*/

#include "flags.h"

unsigned int my_log(unsigned int n, unsigned int base);
int my_put_float2(double nb, int *char_count, specifier_t specifier);
int my_put_science2(double nb, int *char_count, specifier_t specifier);
int my_putchar_printf(const char c, int *count);
int nbr_puissance(double nb);
void my_put_nbr_printf_ll(long long int n, int *char_count);
int find_precision(double nb);

void padding_left_s_c(int str_width, specifier_t specifier, int is_neg,
    int *char_count)
{
    char padding_char = specifier.flag == '0' ? '0' : ' ';
    int flag_plus = specifier.flag == '+' ? 1 : 0;

    if (str_width < specifier.min_width + (-is_neg) + flag_plus &&
        specifier.flag != '-') {
        for (int i = 0; i < specifier.min_width - (str_width + (-is_neg) +
            flag_plus); i++)
            my_putchar_printf(padding_char, char_count);
    }
}

void padding_right_s_c(int str_width, specifier_t specifier, int is_neg,
    int *char_count)
{
    char padding_char = specifier.flag == '0' ? '0' : ' ';
    int flag_plus = specifier.flag == '+' ? 1 : 0;

    if (str_width < specifier.min_width + (-is_neg) + flag_plus &&
        specifier.flag == '-') {
        for (int i = 0; i < specifier.min_width - (str_width + (-is_neg) +
            flag_plus); i++)
            my_putchar_printf(padding_char, char_count);
    }
}

void decide_e_f(int i, double nb, int *count_char, specifier_t specifier)
{
    int find_preci = find_precision(nb < 0 ? -nb : nb);
    double pos_nb = nb < 0 ? -nb : nb;

    if (find_preci < 0)
        find_preci = 0;
    if (i >= 6 || i <= -6) {
        specifier.precision = 5;
        padding_left_s_c(11, specifier, nb < 0 ? -1 : 0, count_char);
        my_put_science2(nb, count_char, specifier);
        padding_right_s_c(11, specifier, nb < 0 ? -1 : 0, count_char);
    } else if (find_preci == 0) {
        padding_left_s_c(my_log((int) pos_nb, 10), specifier, nb < 0 ? -1 : 0,
            count_char);
        my_put_nbr_printf_ll((long long)nb, count_char);
        padding_right_s_c(my_log((int) pos_nb, 10), specifier, nb < 0 ? -1 : 0,
            count_char);
    } else {
        specifier.precision = find_preci;
        my_put_float2(nb, count_char, specifier);
    }
}
