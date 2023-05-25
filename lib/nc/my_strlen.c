/*
** EPITECH PROJECT, 2022
** my_strlen
** File description:
** this will return the length of the array given
*/
int my_strlen(char const *str)
{
    unsigned int count = 0;

    while (str[count] != '\0') {
        count++;
    }
    return (count);
}
