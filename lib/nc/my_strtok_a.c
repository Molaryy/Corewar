/*
** EPITECH PROJECT, 2022
** my_strtok_a
** File description:
** This will split a str into an array of
** strings delimited by any character inside the
** second parameter hence the a for all.
*/

#include <stdlib.h>

#include "nc.h"

int my_strlen(const char *str);

int check_in_delimeter(const char needle, const char *haystack)
{
    for (int i = 0; i < my_strlen(haystack); i++)
        if (needle == haystack[i])
            return TRUE;
    return FALSE;
}

int get_tot_wanted_sec_a(const char * str, char *delimeters)
{
    unsigned int i = 1;
    unsigned int count = 0;

    while (str[i] != '\0' && str[i - 1] != '\0') {
        if (check_in_delimeter(str[i], delimeters) == FALSE &&
            check_in_delimeter(str[i - 1], delimeters) == TRUE) {
            count++;
        }
        i++;
    }
    if (count != 0) {
        count = check_in_delimeter(str[0], delimeters) == FALSE ?
            count + 1 : count;
        return count;
    }
    return 1;
}

int jump_delimeters_a(char const *str, int d, char *delimeters)
{
    for (; check_in_delimeter(str[d], delimeters) == TRUE &&
        str[d] != '\0'; d++);
    return d;
}

int get_size(const char *str, int *d, char *delimeters)
{
    int size = 0;

    for (; check_in_delimeter(str[*d], delimeters) == FALSE &&
        str[*d] != '\0'; (*d)++)
        size++;
    return size;
}

char **my_strtok_a(char const *str, char *delimeters)
{
    int d = 0;
    int size = 0;
    int save = 0;
    unsigned int i = 0;
    unsigned int num_section = get_tot_wanted_sec_a(str, delimeters);
    char **res = malloc(sizeof(char *) * (num_section + 1));

    while (i < num_section) {
        d = jump_delimeters_a(str, d, delimeters);
        size = get_size(str, &d, delimeters);
        res[i] = malloc(sizeof(char) * (size + 1));
        for (int j = 0; j != size; j++)
            res[i][j] = str[d - size + j];
        res[i][size] = '\0';
        i++;
    }
    res[i] = NULL;
    return res;
}
