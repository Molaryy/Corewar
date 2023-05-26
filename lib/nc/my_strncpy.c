/*
** EPITECH PROJECT, 2022
** my_strncpy
** File description:
** This will copy n chars from one str from str
*/
int my_strlen(char const *str);

char *my_strncpy(char *dest, char const *src, int n)
{
    unsigned int i = 0;

    while (i < my_strlen(src) && i < n) {
        dest[i] = src[i];
        i++;
    }
    if ( n > my_strlen(src))
        dest[i] = '\0';
    return dest;
}
