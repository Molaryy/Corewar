/*
** EPITECH PROJECT, 2022
** my_putstr.c
** File description:
** Displays a character of a string 1 by 1
*/

#include <jb.h>

extern void my_putstr(char const *str)
{
    size_t i = 0;

    if (str == NULL) {
        my_printf("(NULL)");
        return;
    }
    for (; str[i] ; i++)
        write(1, &str[i], 1);
}
