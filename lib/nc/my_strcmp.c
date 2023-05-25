/*
** EPITECH PROJECT, 2022
** my_strcmp
** File description:
** This will compare the first char of two strings
*/

int evaluate_diff_char_placing(char const a, char const b)
{
    if (a < b)
        return -1;
    else if (a > b)
        return 1;
}

int evaluate_diff_char(char const a, char const b)
{
    if (a == '\0' && b != '\0')
        return -1;
    else if (a != '\0' && b == '\0')
        return 1;
    return evaluate_diff_char_placing(a, b);
}

int my_strcmp(char const *s1, char const *s2)
{
    unsigned int i = 0;

    while (s1[i] != '\0' || s2[i] != '\0') {
        if (s1[i] == s2[i]) {
            i++;
            continue;
        }
        return evaluate_diff_char(s1[i], s2[i]);
        i++;
    }
    return 0;
}

int my_strcmp_f(char const *s1, char const *s2, int index)
{
    unsigned int i = 0;

    while ((s1[i] != '\0' || s2[i] != '\0') && i < index) {
        if (s1[i] == s2[i]) {
            i++;
            continue;
        }
        return evaluate_diff_char(s1[i], s2[i]);
        i++;
    }
    return 0;
}
