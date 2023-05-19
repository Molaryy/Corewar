/*
** EPITECH PROJECT, 2023
** lib
** File description:
** my_strchr
*/

#include "jb.h"

extern char* my_strchr(const char* __first_str, char index)
{
    while (*(__first_str) != '\0') {
        if (*(__first_str) == index)
            return ((char*)__first_str);
        __first_str++;
    }
    if (*(__first_str) == index) {
        return ((char*)__first_str);
    }
    return NULL;
}
