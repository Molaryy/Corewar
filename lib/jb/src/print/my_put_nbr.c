/*
** EPITECH PROJECT, 2022
** my_put_nbr
** File description:
** my put numbr
*/

#include "jb.h"

int my_put_nbr(int nb)
{
    char c = '0';
    int number = 1;

    if (nb == 0) {
        write(1, "0", 1);
        return 1;
    }
    for (; (nb / number) >= 10; number *= 10);
    for (; number > 0; number = number / 10) {
        c = (nb / number) % 10 + '0';
        write (1, &c, 1);
    }
    return 0;
}
