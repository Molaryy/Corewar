/*
** EPITECH PROJECT, 2022
** my_str_isnum
** File description:
** This will return 1 if there is only numbers in the string and 0 if not
*/

int test_is_num(char c);

int my_str_isnum(char const *str)
{
    unsigned int i = 0;

    while (str[i] != '\0') {
        if ( test_is_num(str[i]) != 1)
            return 0;
        i++;
    }
    return 1;
}
