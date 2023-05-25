/*
** EPITECH PROJECT, 2022
** task01
** File description:
** This will copy a string into another of same size
*/

char* my_strcpy(char *dest, char const *src)
{
    unsigned int i = 0;

    while (src[i] != '\0') {
        dest[i] = (char) src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}
