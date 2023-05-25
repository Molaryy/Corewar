/*
** EPITECH PROJECT, 2022
** my_str_islower
** File description:
** this returns 1 if the string only contains lowercase letters
*/

int test_is_low(char c)
{
    if ( c >= 97 && c <= 122 ) {
        return 1;
    }
    return -1;
}

int my_str_islower(char const *str)
{
    unsigned int i = 0;
    while (str[i] != '\0') {
        if (test_is_low(str[i]) != 1)
            return 0;
        i++;
    }
    return 1;
}
