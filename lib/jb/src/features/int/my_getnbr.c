/*
** EPITECH PROJECT, 2022
** My_getnbr.c
** File description:
** Returns a number from a string
*/

static int is_digit(char c)
{
    if (c >= '0' && c <= '9')
        return 1;
    return (0);
}

static int is_neg(char const *str)
{
    int n = 1;

    for (int i = 0; str[i] == '-' || str[i] == '+'; i++) {
        if (str[0] == '-')
            n *= -1;
    }
    return (n);
}

static int get_start_index(char const *str)
{
    int i = 0;
    int n = 0;

    for (; str[i] != '\0'; i++) {
        if (is_digit(str[i]))
            return (n);
        if (is_digit(str[i]) == 0)
            n++;
    }
    return (n);
}

int my_getnbr(char const *str)
{
    int	nb = 0;
    int	i = get_start_index(str);
    int	neg = is_neg(str);

    while (str[i] != '\0' && is_digit(str[i])) {
        nb *= 10;
        nb += str[i] - 48;
        i += 1;
    }
    return (nb * neg);
}
