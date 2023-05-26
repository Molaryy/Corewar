/*
** EPITECH PROJECT, 2022
** my_putstr
** File description:
** this functino will display the value of a string
*/

void my_putchar(char c);

int my_putstr(char const *str)
{
    unsigned int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
    return 0;
}
