/*
** EPITECH PROJECT, 2022
** my_str_isalpha
** File description:
** This will return 1 if the string only contains an char and 0 if not
*/

int test_is_num(char c)
{
    if (c >= '0' && c <= '9') {
        return 1;
    }
    return -1;
}

int test_is_char(char c)
{
    if ( (c >= 65 && c <= 90 ) ||
    ( c >= 97 && c <= 122 )){
        return 1;
    }
    return -1;
}

int is_alpha(char c)
{
    if (test_is_num(c) == 1 || test_is_char(c) == 1)
        return 1;
    return -1;
}

int my_str_isalpha(char const *str)
{
    unsigned int i = 0;

    while (str[i] != '\0') {
        if ( is_alpha(str[i]) != 1 )
            return 0;
        i++;
    }
    return 1;
}
