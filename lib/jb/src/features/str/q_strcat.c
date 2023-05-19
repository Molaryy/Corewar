/*
** EPITECH PROJECT, 2023
** c pool
** File description:
** true
*/

extern char *q_strcat(char *dest, char const *src)
{
    int i;
    int j;

    for (i = 0; dest[i] != '\0'; i++) {
    }
    for (j = 0; src[j] != '\0'; j++, i++) {
        dest[i] = src[j];
    }
    dest[i] = '\0';
    return dest;
}
