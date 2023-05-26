/*
** EPITECH PROJECT, 2022
** update_specifier2
** File description:
** helper function for specifier parsing
*/

int is_valid_conversion_specifier(char c)
{
    if (c == 'a' || c == 'A' || c == 'o' || c == '%' ||
        c == 'x' || c == 'X' || c == 'n' || c == 'g' || c == 'G' ||
        c == 'p' || c == 's' || c == 'S' || c == 'c' || c == 'i' ||
        c == 'd' || c == 'u' || c == 'e' || c == 'E' || c == 'f') {
        return 1;
    }
    return -1;
}
