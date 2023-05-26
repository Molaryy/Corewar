/*
** EPITECH PROJECT, 2022
** my_isneg
** File description:
** This will check if the input is pos or neg
*/

void my_putchar(char c);

int my_isneg(int n)
{
    if (n < 0) {
        my_putchar(78);
    } else if (n >= 0) {
        my_putchar(80);
    }
    my_putchar(10);
    return (0);
}
