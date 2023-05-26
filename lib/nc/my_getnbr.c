/*
** EPITECH PROJECT, 2022
** my_getnbr
** File description:
** this will return a number and as input get string
*/

int compute_char(char c, int number)
{
    if ((unsigned char)c >= '0' && (unsigned char)c <= '9'){
        number *= 10;
        number += (int)((unsigned char)c - 48);
    }
    return number;
}

int my_getnbr(char const *str)
{
    int number = 0;
    unsigned int i = 0;
    int sign = 1;
    int passed_number = 0;

    while (str[i] != '\0' &&
        (((unsigned char) str[i] >= '0' && (unsigned char) str[i] <= '9' ) ||
        (((unsigned char) str[i] == '-' || ((unsigned char) str[i] == '+')) &&
        passed_number == 0))) {
        if (str[i] == '-' )
            sign *= -1;
        if (str[i] >= '0' && str[i] <= '9') {
            number = compute_char(str[i], number);
            passed_number = 1;
        }
        i++;
    }
    return number * sign;
}
