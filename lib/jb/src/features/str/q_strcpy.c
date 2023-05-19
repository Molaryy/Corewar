/*
** EPITECH PROJECT, 2023
** lib
** File description:
** q_strcpy
*/

extern char *q_strcpy(char *dest, char const *src)
{
    int a = 0;

    while (src[a] != '\0') {
        dest[a] = src[a];
        a++;
    }
    dest[a] = '\0';
    return (dest);
}
