/*
** EPITECH PROJECT, 2023
** my_trum
** File description:
** jkl
*/

#include "jb.h"

char *clean_string(char* string)
{
    int end_line = my_strlen(string) - 1;
    int start_string = 0;

    for (start_string = 0; string[start_string] == ' '; start_string++);
    while ((string[end_line] == ' ' || string[end_line] == '\n'
            || string[end_line] == '\t') && end_line >= start_string) {
        end_line--;
    }
    for (int i = start_string; i <= end_line; i++) {
        string[i - start_string] = string[i];
    }
    string[end_line - start_string + 1] = '\0';
    return string;
}
