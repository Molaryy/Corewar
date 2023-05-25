/*
** EPITECH PROJECT, 2022
** my_put_nbr
** File description:
** This will output the interger value the script was given as text
*/

void my_putchar(char c);

void frec(int i, char *res, int index)
{
    if (i != 0) {
        frec(i / 10);
        my_putchar(i % 10 + '0');
    } else {
        return;
    }
}

void my_put_nbr(int n)
{
    char *res = malloc(sizeof(char) * 6);

    for (int i = 0; i < 6; i++)
        res[i] = '\0';
    if (n < 0) {
        my_putchar('-');
        n *= -1;
    }
    if (n == 0) {
        my_putchar('0');
        return;
    }
    frec(n, res, 0);
}
