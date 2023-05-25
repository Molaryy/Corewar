/*
** EPITECH PROJECT, 2022
** my_put_base_printf
** File description:
** this will output the int in base given hex or octal for example
*/

int my_strlen(char const *str);
int my_putchar_printf(const char, int *count);

void brec_printf(long long int i, char * base, int *count, int *error)
{
    int res = 1;

    if ( i != 0 ) {
        brec_printf(i / my_strlen(base), base, count, error);
        res = my_putchar_printf( base[i % my_strlen(base)], count);
        if (res == -1)
            *error = -1;
    } else {
        return;
    }
}

int my_put_base_printf(long long int n, char * base, int *count)
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
    brec_printf(n, base, count, &error);
    return error;
}
