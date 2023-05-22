/*
** EPITECH PROJECT, 2022
** my_put_nbr
** File description:
** my put numbr
*/

#include "jb.h"

extern int my_put_nbr(int nb)
{
    long max = 2147483647;
    long min = -2147483647;

    if (nb >= max)
        my_putstr("2147483647");
    if (nb <= min)
        my_putstr("-2147483647");
    if (nb < 0) {
        my_putchar('-');
        my_put_nbr(nb * -1);
        return 0;
    }
    if (nb >= 10) {
        my_put_nbr(nb / 10);
        my_putchar(nb % 10 + '0');
    } else if (nb < 10) {
        my_putchar(nb + '0');
    }
    return 0;
}
