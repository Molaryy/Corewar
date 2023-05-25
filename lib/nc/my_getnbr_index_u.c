/*
** EPITECH PROJECT, 2023
** my_getnbr_index_u.c
** File description:
** my_getnbr but from index and returns an unsigned int
*/

int compute_char2(char c, int number)
{
    if ((unsigned char)c >= '0' && (unsigned char)c <= '9'){
        number *= 10;
        number += (int)((unsigned char)c - 48);
    }
    return number;
}

unsigned int my_getnbr_index_u(char const *str, unsigned int index)
{
    unsigned int number = 0;
    unsigned int i = index;
    int passed_number = 0;

    while (str[i] != '\0' &&
        (((unsigned char) str[i] >= '0' && (unsigned char) str[i] <= '9' ) ||
        (((unsigned char) str[i] == '-' || ((unsigned char) str[i] == '+')) &&
        passed_number == 0))) {
        if (str[i] >= '0' && str[i] <= '9') {
            number = compute_char2(str[i], number);
            passed_number = 1;
        }
        i++;
    }
    return number;
}
