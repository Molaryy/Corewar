/*
** EPITECH PROJECT, 2022
** my_strupcase
** File description:
** This will convert the str to uppercase
*/

char * my_strupcase(char *str)
{
    unsigned int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= 97 && str[i] <= 122) {
            str[i] -= 32;
        }
        i++;
    }
    return str;
}
