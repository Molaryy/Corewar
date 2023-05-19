/*
** EPITECH PROJECT, 2022
** my_put_nbr
** File description:
** my put numbr
*/

#include "jb.h"

void my_putnbr_base(int nb, char const *base)
{
    int i = 0;

    if (nb < 0) {
        my_putchar('-');
        nb *= -1;
    }
    i = nb % my_strlen(base);
    if (nb >= my_strlen(base)) {
        nb = nb / my_strlen(base);
        my_putnbr_base(nb, base);
        my_putchar(base[i]);
    } else
        my_putchar(base[i]);
}
