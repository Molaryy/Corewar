/*
** EPITECH PROJECT, 2022
** my_getnbr_printf
** File description:
** This will get the number from a string
*/

int compute_char(char c, int number);

int my_getnbr_printf(char const *str, int i)
{
    int number = 0;
    int sign = 1;
    int passed_number = 0;

    while (str[i] != '\0' &&
        (((unsigned char) str[i] >= '0' && (unsigned char) str[i] <= '9' ) &&
        passed_number == 0)) {
        if (str[i] >= '0' && str[i] <= '9')
            number = compute_char(str[i], number);
        else
            return number;
        i++;
    }
    return number;
}
