/*
** EPITECH PROJECT, 2022
** my_str_isupper
** File description:
** This will return if the string given is composed only
** of capital letters else 0
*/

int test_is_upper(char c)
{
    if ( c >= 'A' && c <= 'Z') {
        return 1;
    }
    return -1;
}

int my_str_isupper(char const *str)
{
    unsigned int i = 0;

    while (str[i] != '\0') {
        if (test_is_upper(str[i]) != 1)
            return 0;
        i++;
    }
    return 1;
}
