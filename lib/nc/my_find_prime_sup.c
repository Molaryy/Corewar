/*
** EPITECH PROJECT, 2022
** my_find_prime_sup
** File description:
** This function will output the lowest prime number between two bounds
*/

int my_is_prime(int nb);

int find_prime_rec(int nb)
{
    if ( my_is_prime(nb) == 1)
        return nb;
    else
        return find_prime_rec(nb + 1);
}

int my_find_prime_sup(int nb)
{
    return find_prime_rec(nb);
}
