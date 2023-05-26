/*
** EPITECH PROJECT, 2022
** my_swap
** File description:
** This will swap two integers
*/

void my_swap(int *a, int *b)
{
    int c;

    c = *a;
    *a = *b;
    *b = c;
}
