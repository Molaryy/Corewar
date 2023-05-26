/*
** EPITECH PROJECT, 2022
** my_str_isnum
** File description:
** This will return 1 if there is only numbers in the string and 0 if not
*/

#include "jb.h"

extern bool my_str_isnum(char const *str)
{
    unsigned int i = 0;

    while (str[i] != '\0') {
        if (!is_digit(str[i]))
            return false;
        i++;
    }
    return true;
}
