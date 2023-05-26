/*
** EPITECH PROJECT, 2022
** my_compute_power_rec
** File description:
** This will compute nb to the power of p recursively
*/

int check_is_neg2(int n)
{
    if (n < 0)
        return -1;
    else
        return 1;
}

int test_if_overflow2(int neg, int p, int last_res, int next_res)
{
    if ( neg == -1 && ( p % 2 == 0 && check_is_neg2(next_res == 1) ) )
        return 1;
    else if ( neg == 1 && next_res < last_res )
        return 1;
    return 0;
}

int power_is_satisfy2(int n)
{
    if ( n == 0 )
        return 1;
    else if ( n < 0)
        return 0;
    return -1;
}

int powrec(int last_n, int p, int is_neg)
{
    if ( p > 1) {
        int next_n = last_n * powrec(last_n, p - 1, is_neg);
        if ( test_if_overflow2 (is_neg, p, last_n, next_n ) == 1 )
            return 0;
        return next_n;
    } else
        return last_n;
}

int my_compute_power_rec(int nb, int p)
{
    int is_comply = power_is_satisfy2(p);
    int is_neg = check_is_neg2(nb);

    if ( is_comply >= 0 )
        return is_comply;
    return powrec(nb, p, is_neg);
}
