/*
** EPITECH PROJECT, 2022
** str
** File description:
** str contains char?
*/

#include "jb.h"

bool str_contains_char(char const *str, char to_find)
{
    for (size_t i = 0; str[i]; i++) {
        if (str[i] == to_find)
            return true;
    }
    return false;
}
