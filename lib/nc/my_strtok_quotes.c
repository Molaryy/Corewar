/*
** EPITECH PROJECT, 2023
** my_strtok_quotes.c
** File description:
** this will do the same as strtok but will handle quotes and inhibitors
*/

#include "nc.h"

int jump_delimiters_quotes(char *str, int *i, char *delimiter)
{
    int check = 0;

    for (; str[*i] && check_in_delimeter(str[*i], delimiter)
        == TRUE; (*i)++, check++);
    return check == 0 ? FALSE : TRUE;
}

int get_str_size(char *str, char *delimiter, int *i)
{
    int size = 0;
    int is_in_quotes = FALSE;

    for (; !(check_in_delimeter(str[size], delimiter) == TRUE && is_in_quotes
        == FALSE) && str[size]; size++) {
        if (str[size] == '"' && is_in_quotes == TRUE && str[size - 1]
            != '\\') {
            is_in_quotes = FALSE;
            continue;
        }
        if (str[size] == '"' && is_in_quotes == FALSE && str[size - 1]
            != '\\') {
            is_in_quotes = TRUE;
        }
    }
    return size;
}

void cpy_str(char *str, char *res, int *i, int size)
{
    int j;
    int k = 0;
    int in_quotes = 0;

    for (j = 0; k < size && in_quotes < 2; j++, (*i)++, k++) {
        res[j] = str[*i];
        if (str[*i] == '\\' && str[*i - 1] != '\\') {
            res[j] = str[++(*i)];
            k++;
            continue;
        }
        if (str[*i - 1] != '\\' && str[*i] == '"') {
            res[j] = str[++(*i)];
            k++;
            in_quotes++;
        }
        if (in_quotes == 2)
            break;
    }
    res[j] = '\0';
}

char **my_strtok_quotes(char *str, char *delimiter)
{
    char *tmp_str;
    char **res = malloc(sizeof(char*));
    int size = 0;
    int i = 0;

    res[0] = NULL;
    while (str[i]) {
        if (jump_delimiters_quotes(str, &i, delimiter) == TRUE)
            continue;
        size = get_str_size(&str[i], delimiter, &i);
        tmp_str = malloc(sizeof(char) * (size + 1));
        tmp_str[size] = '\0';
        cpy_str(str, tmp_str, &i, size);
        res = cust_realloc_char(res, tmp_str);
        if (str[i] == '\0' || str[i - 1] == '\0')
            break;
        i++;
    }
    return res;
}
