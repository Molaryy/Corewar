/*
** EPITECH PROJECT, 2023
** PROJECT
** File description:
** is_separator
*/

#include "jb.h"

extern bool is_separator(char c, char const *separator)
{
    if (!separator)
        return false;
    for (size_t i = 0; separator[i]; i++) {
        if (separator[i] == c)
            return false;
    }
    return true;
}
