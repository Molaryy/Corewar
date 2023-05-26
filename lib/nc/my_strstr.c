/*
** EPITECH PROJECT, 2022
** my_strstr
** File description:
** This will find a string (needle) in another string (haystack)
*/

#include <stdlib.h>

int my_strlen(const char * str);

int evaluate_equal(char const *str, char const *to_find)
{
    unsigned int i = 0;

    while (str[i] != '\0' && to_find[i] != '\0') {
        if (str[i] != to_find[i] && i < my_strlen(to_find)) {
            return -1;
        }
        i++;
    }
    return 1;
}

char *my_strstr(char *str, char const *to_find)
{
    unsigned int needle_len = my_strlen(to_find) + 1;
    unsigned int haystack_len = my_strlen(str) + 1;

    if (needle_len <= 1) {
        return str;
    }
    for (unsigned int i = 0; i <= haystack_len; i++) {
        if (evaluate_equal(str + i, to_find) == 1) {
            return str + i;
        }
    }
    return NULL;
}
