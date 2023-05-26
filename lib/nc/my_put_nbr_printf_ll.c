/*
** EPITECH PROJECT, 2022
** my_printf put nbr simple
** File description:
** this includes the char count var
*/

int my_putchar_printf(const char c, int *count);

void frec_printf3(long long int n, int *char_count)
{
    if (n != 0) {
        frec_printf3(n / 10, char_count);
        my_putchar_printf(n % 10 + '0', char_count);
    } else {
        return;
    }
}

void my_put_nbr_printf_ll(long long int n, int *char_count)
{
    if (n < 0) {
        my_putchar_printf('-', char_count);
        n *= -1;
    }
    if (n == 0) {
        my_putchar_printf('0', char_count);
        return;
    }
    frec_printf3(n, char_count);
}
