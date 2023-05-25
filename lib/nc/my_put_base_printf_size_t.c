/*
** EPITECH PROJECT, 2022
** my_put_base_printf
** File description:
** this will output the int in base given hex or octal for example
*/

#include <stddef.h>

int my_putchar_printf(const char, int *count);
int my_strlen(char const *str);

void brec_printf2(size_t i, char *base, int *count, int *error)
{
    int res = 1;

    if ( i != 0 ) {
        brec_printf2(i / (long long)my_strlen(base), base, count, error);
        res = my_putchar_printf( base[i % my_strlen(base)], count);
        if (res == -1)
            *error = -1;
    } else {
        return;
    }
}

int my_put_base_printf2(size_t n, char *base, int *count)
{
    int error = 1;

    if ( n < 0 ) {
        my_putchar_printf('-', count);
        n *= -1;
    }
    if ( n == 0 ) {
        my_putchar_printf('0', count);
        return 1;
    }
    brec_printf2(n, base, count, &error);
    return error;
}
