/*
** EPITECH PROJECT, 2022
** my_strncmp
** File description:
** same as strcmp but with starting from n
*/

int evaluate_diff_char(char const a, char const b);
int my_strlen(char *str);

int get_min_len(char const *a, char const *b)
{
    unsigned int a_len = my_strlen( (char *) a);
    unsigned int b_len = my_strlen( (char *) b);

    if (a_len < b_len)
        return a_len;
    else
        return b_len;
}

int my_strncmp(char const *s1, char const *s2, int n)
{
    int min_len = get_min_len(s1, s2);

    for (int j = 0; j < min_len && j < n; j++) {
        if (s1[j] == s2[j])
            continue;
        else
            return evaluate_diff_char(s1[j], s2[j]);
    }
    return 0;
}
