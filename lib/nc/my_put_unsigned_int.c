/*
** EPITECH PROJECT, 2022
** my_put_unsigned_int.c
** File description:
** put uigned int
*/

int my_putchar_printf(char c, int *char_count);

void frec3(unsigned int i, int *char_count)
{
    if (i != 0) {
        frec3(i / 10, char_count);
        my_putchar_printf(i % 10 + '0', char_count);
    } else {
        return;
    }
}

void my_put_unsigned_int(unsigned int n, int *char_count)
{
    if (n == 0) {
        my_putchar_printf('0', char_count);
        return;
    }
    frec3(n, char_count);
}
