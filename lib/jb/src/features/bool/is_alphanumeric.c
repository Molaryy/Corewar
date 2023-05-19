/*
** EPITECH PROJECT, 2023
** B-PSU-200-REN-2-1-42sh-mohammed.jbilou
** File description:
** is_alphanumeric.c
*/

#include "jb.h"

extern bool is_char_alphanumeric(char c)
{
    if ((c < 'a' || c > 'z')
        && (c < 'A' || c > 'Z')
        && (c < '0' || c > '9')
        && (c != '_'))
        return false;
    return true;
}

extern bool is_str_alphanumeric(char *str)
{
    for (size_t i = 0; str[i] ; i++){
        if (!is_char_alphanumeric(str[i]))
            return false;
    }
    return true;
}
