/*
** EPITECH PROJECT, 2022
** task03 my_show_word_array
** File description:
** this will display all contents or a word array
*/

#include <stdio.h>
int my_putstr(char const *str);
void my_putchar(char c);

int my_show_word_array( char * const * tab )
{
    unsigned int i = 0;

    while (tab[i] != 0) {
        my_putstr(tab[i]);
        my_putchar('\n');
        i++;
    }
    return 0;
}
