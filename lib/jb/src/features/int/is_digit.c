/*
** EPITECH PROJECT, 2023
** is_digit
** File description:
** check if number
*/

#include "jb.h"

bool is_digit(char c)
{
    if (c <= '9' && c >= '0')
        return true;
    else
        return false;
}
