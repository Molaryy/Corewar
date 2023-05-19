/*
** EPITECH PROJECT, 2022
** My_putchar
** File description:
** My_pucthar
*/

#include <unistd.h>

extern int my_putchar(char c)
{
    write (1, &c, 1);
    return 1;
}
