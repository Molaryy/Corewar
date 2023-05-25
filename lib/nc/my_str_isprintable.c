/*
** EPITECH PROJECT, 2022
** my_str_isprintable
** File description:
** This will return 1 if all char in str is in ascii if not reutrn 0
*/

int is_ascii(char c)
{
    if (c >= 0 || c <= 127)
        return 1;
    else
        return 0;
}

int my_str_isprintable(char const *str)
{
    unsigned int i = 0;

    while (str[i] != '\0') {
        if (is_ascii(str[i]) == -1) {
            return 0;
        }
        i++;
    }
    return 1;
}
