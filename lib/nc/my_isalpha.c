/*
** EPITECH PROJECT, 2022
** my_str_isalpha
** File description:
** This will return 1 if the string only contains an char and 0 if not
*/

int test_is_num(char c);
int test_is_char(char c);

int my_isalpha(char c)
{
    if (test_is_num(c) == 1 || test_is_char(c) == 1)
        return 1;
    return -1;
}
