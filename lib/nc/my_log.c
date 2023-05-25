/*
** EPITECH PROJECT, 2022
** logarithm
** File description:
** This will compute log for the every base
*/

unsigned int my_log(unsigned int n, unsigned int base)
{
    int log = 0;

    while ( n >= 10 ) {
        n /= 10;
        log += 1;
    }
    return log;
}

unsigned int my_log2(unsigned int n, unsigned int base)
{
    return (n > 1) ? 1 + my_log2(n / base, base) : 0;
}

unsigned int my_log16(unsigned int n)
{
    int log = 0;

    while (n > 16) {
        n /= 16;
        log++;
    }
    log++;
    return log;
}

int my_log8(long long int nb)
{
    int n = 0;
    while (nb > 8) {
        nb /= 8;
        n++;
    }
    n += 1;
    return n;
}
