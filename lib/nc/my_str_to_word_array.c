/*
** EPITECH PROJECT, 2022
** task04 my_str_to_word_array
** File description:
** This will split a string into an array of words
*/

#include <stdlib.h>

int my_isalpha(char c);

int get_tot_num_of_words(const char * str)
{
    unsigned int i = 0;
    unsigned int count = 0;

    while (str[i] != '\0') {
        if (my_isalpha(str[i + 1]) < 0 && my_isalpha(str[i]) == 1)
            count++;
        i++;
    }
    if (my_isalpha(str[i]) == 0) {
        count--;
    }
    return count;
}

int jump_all_non_alpha(char const *str, int d)
{
    for (; my_isalpha(str[d]) < 0; d++);
    return d;
}

char ** my_str_to_word_array(char const *str)
{
    int d = 0;
    int size = 0;
    int save = 0;
    unsigned int i = 0;
    unsigned int num_of_words = get_tot_num_of_words(str);
    char **res = malloc(sizeof(char *)*(num_of_words + 1));

    while ( i < num_of_words) {
        size = 0;
        d = jump_all_non_alpha(str, d);
        for (; my_isalpha(str[d]) == 1; d++)
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
