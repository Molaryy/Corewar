/*
** EPITECH PROJECT, 2022
** my_strlowcase
** File description:
** This will convert a string to lowercase
*/

char * my_strlowcase(char *str)
{
    unsigned int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= 65 && str[i] <= 90) {
            str[i] += 32;
        }
        i++;
    }
    return str;
}
