/*
** EPITECH PROJECT, 2022
** my_strcapitalize
** File description:
** This will capitalize the first letter of a sentence and others
*/

char *my_strlowcase(char *str);

char *my_charupcase(char * str)
{
    if (*str >= 97 && *str <= 122) {
        *str -= 32;
    }
    return str;
}

char *my_strcapitalize(char *str)
{
    unsigned int i = 0;

    my_strlowcase(str);
    my_charupcase(str);
    while (str[i] != '\0'){
        if (str[i] == ' ' || str[i] == '-' || str[i] == '+') {
            my_charupcase(str + i + 1);
        }
        i++;
    }
    return str;
}
