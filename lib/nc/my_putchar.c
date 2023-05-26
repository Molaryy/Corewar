/*
** EPITECH PROJECT, 2022
** my_putchar
** File description:
** This function will disp ascii char
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
