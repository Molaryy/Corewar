/*
** EPITECH PROJECT, 2022
** my_strcmp
** File description:
** My_strcmp
*/

#include "jb.h"

bool my_strcmp(char const *s1, char const *s2)
{
    size_t len_s2 = 0;
    size_t len_s1 = 0;

    if (s1 == NULL || s2 == NULL)
        return false;
    len_s1 = my_strlen(s1);
    len_s2 = my_strlen(s2);
    if (len_s1 != len_s2)
        return false;
    for (int i = 0; s1[i] != '\0'; i++){
        if (s1[i] != s2[i])
            return false;
    }
    return (true);
}
