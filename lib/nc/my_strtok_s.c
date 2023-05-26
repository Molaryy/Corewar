/*
** EPITECH PROJECT, 2022
** my_strtok_s
** File description:
** This will split a str into an array of
** strings delimited by a given char
** and will start at given index
*/

#include <stdlib.h>

int get_tot_wanted_sec(const char * str, char delimeter);
int jump_delimeters(char const *str, int d, char delimeter);

char **my_strtok_s(char const *str, char delimeter, int index)
{
    int d = index;
    int size = 0;
    int save = 0;
    unsigned int i = 0;
    unsigned int num_section = get_tot_wanted_sec(str, delimeter);
    char ** res = malloc(sizeof(char *) * (num_section + 1));

    while (i < num_section) {
        size = 0;
        d = jump_delimeters(str, d, delimeter);
        for (; str[d] != delimeter && str[d] != '\0'; d++)
            size++;
        res[i] = malloc(sizeof(char) * (size + 1));
        for (int j = 0; j != size; j++)
            res[i][j] = str[d - size + j];
        res[i][size] = '\0';
        i++;
    }
    res[i] = NULL;
    return res;
}
