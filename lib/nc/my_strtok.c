/*
** EPITECH PROJECT, 2022
** my_strtok
** File description:
** This will split a str into an array of
** strings delimited by a given char
*/

#include <stdlib.h>

int my_putstr(char const *);
void my_putchar(char c);

int get_tot_wanted_sec(const char * str, char delimeter)
{
    unsigned int i = 1;
    unsigned int count = 0;

    while (str[i] != '\0' && str[i - 1] != '\0') {
        if (str[i] != delimeter && str[i - 1] == delimeter) {
            count++;
        }
        i++;
    }
    if (count != 0) {
        count = str[0] != delimeter ? count + 1 : count;
        return count;
    }
    return 1;
}

int jump_delimeters(char const *str, int d, char delimeter)
{
    for (; str[d] == delimeter && str[d] != '\0'; d++);
    return d;
}

char ** my_strtok(char const * str, char delimeter)
{
    int d = 0;
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
