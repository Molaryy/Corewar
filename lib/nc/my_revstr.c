/*
** EPITECH PROJECT, 2022
** my_revstr
** File description:
** This will reverse a string
*/

int my_strlen(const char * str);

void my_swap_char(char *a, char *b)
{
    char c;

    c = *a;
    *a = *b;
    *b = c;
}

char* my_revstr(char *str)
{
    int sizeofstring = my_strlen(str) - 1;
    int count = 0;

    if (sizeofstring <= 0)
        return str;
    while ( count <= (int)( ( sizeofstring ) / 2 ) ) {
        my_swap_char(&str[count], &str[sizeofstring - count]);
        count++;
    }
    return str;
}
