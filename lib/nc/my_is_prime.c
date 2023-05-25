/*
** EPITECH PROJECT, 2022
** my_is_prime
** File description:
** This wil test if the number given is a prime number
*/
int found_whole(int x, int n)
{
    if (x == n)
        return 0;
    else if ((int)(n / x) * x == n)
        return 1;
    return 0;
}

int prec(int test_value, int nb)
{
    if (test_value == 1 && nb != 1)
        return 1;
    else if ( nb == 0 || nb == 1 || found_whole(test_value, nb) == 1)
        return 0;
    return prec(test_value - 1, nb);
}

int my_is_prime(int nb)
{
    return prec(nb, nb);
}
