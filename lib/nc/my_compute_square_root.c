/*
** EPITECH PROJECT, 2022
** my_compute_square_root
** File description:
** This will compute the square root of the number given
*/

int is_root(int guess, int nb)
{
    if (guess * guess == nb)
        return 1;
    else if (guess == 0)
        return -1;
    return 0;
}

int root(int guess, int nb)
{
    unsigned int test = is_root(guess, nb);
    if (test == 1)
        return guess;
    else if (test == -1)
        return 0;
    return root(guess - 1, nb);
}

int my_compute_square_root(int nb)
{
    return root(nb, nb);
}
