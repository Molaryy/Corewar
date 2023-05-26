/*
** EPITECH PROJECT, 2022
** my_putstr
** File description:
** this functino will display the value of a string
*/

void my_putchar_printf(char c, int *char_count);

int my_putstr_printf_inte(char const *str, int *char_count)
{
    unsigned int i = 0;

    while (str[i] != '\0') {
        my_putchar_printf(str[i], char_count);
        i++;
    }
    return 0;
}
