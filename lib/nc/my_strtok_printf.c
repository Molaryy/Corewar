/*
** EPITECH PROJECT, 2022
** my_strtok_printf
** File description:
** This is the custom strtok for printf
*/

#include <stdlib.h>

int my_putstr(char const *);
void my_putchar(char c);
int my_strlen(char const *str);

int is_in_delimeter_printf(char search_for, char *search_in)
{
    for (int i = 0; i < my_strlen(search_in); i++) {
        if (search_in[i] == search_for)
            return 0;
    }
    return -1;
}

int get_tot_wanted_sec_printf(const char *str, char *delimeter)
{
    unsigned int i = 0;
    unsigned int count = 0;

    while (str[i] != '\0') {
        if (is_in_delimeter_printf(str[i + 1], delimeter) == -1 &&
            is_in_delimeter_printf(str[i], delimeter) == 0) {
            count++;
        }
        i++;
    }
    count = is_in_delimeter_printf(str[i - 1], delimeter) ==
            0 ? count - 1 : count;
    count = is_in_delimeter_printf(str[0], delimeter) == -1 ? count + 1 : count;
    return count;
}

int jump_delimeters_printf(char const *str, int d, char *delimeter)
{
    for (; is_in_delimeter_printf(str[d], delimeter) == 0; d++);
    return d;
}

char ** my_strtok_printf(char const * str, int pos, char *delimeter)
{
    int d = pos;
    int size = 0;
    int save = 0;
    unsigned int i = 0;
    unsigned int num_section = get_tot_wanted_sec_printf(str, "%");
    char ** res = malloc(sizeof(char *) * (num_section + 1));

    while (i < num_section) {
        size = 0;
        d = jump_delimeters_printf(str, d, delimeter);
        for (; is_in_delimeter_printf(str[d], delimeter) == -1; d++)
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
