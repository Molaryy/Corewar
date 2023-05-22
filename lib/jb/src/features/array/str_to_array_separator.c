/*
** EPITECH PROJECT, 2022
** my_str_to_word_array
** File description:
** A function that splits into words
*/

#include "jb.h"

static size_t my_cols_counter(char const *str, size_t i, char *separator)
{
    size_t word = 0;

    for (; str[i] != '\0' && !is_separator(str[i], separator); i++);
    for (; str[i] != '\0' && is_separator(str[i], separator); i++)
        word++;
    return word;
}

static size_t count_lines(char const *str, char *separator)
{
    size_t n = 0;

    for (size_t i = 0; str[i] != '\0'; i++) {
        if ((is_separator(str[i], separator))
        && (!is_separator(str[i + 1], separator)
        || str[i + 1] == '\0')) {
            n++;
        }
    }
    return (n);
}

extern char **str_to_array_separator(char const *str, char *separator)
{
    size_t lines = count_lines(str, separator);
    char **array = malloc(sizeof(char *) * (lines + 1));

    if (!array)
        return NULL;
    for (size_t i = 0, k = 0, j = 0, cols = 0; i < lines; i++) {
        cols = my_cols_counter(str, j, separator);
        if (!(array[i] = malloc(sizeof(char) * (cols + 1))))
            return NULL;
        array[i][cols] = '\0';
        for (; str[j] != '\0' && (!is_separator(str[j], separator)); j++);
        for (; str[j] != '\0' && is_separator(str[j], separator); j++, k++) {
            array[i][k] = str[j];
        }
        k = 0;
    }
    array[lines] = NULL;
    return (array);
}
