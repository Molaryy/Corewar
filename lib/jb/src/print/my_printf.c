/*
** EPITECH PROJECT, 2022
** mini_printf
** File description:
** little functions that we can use with
*/

#include <stdarg.h>
#include "jb.h"

static void flags(char c, int *i, va_list list, int n)
{
    if (c == 'c' || c == 's' || c == 'i' || c == 'd' || c == '%' || c == 'f'
    || c == 't')
        *i += 1;

    switch (c) {
        case 'c': n += my_putchar(va_arg(list, int)); break;
        case 's': my_putstr(va_arg(list, char *)); break;
        case 'i': n += my_put_nbr(va_arg(list, int)); break;
        case 'd': n += my_put_nbr(va_arg(list, int)); break;
        case 't': print_tab(va_arg(list, char **)); break;
        case '%': n += my_putchar('%'); break;
    }
}

int my_printf(const char *format, ...)
{
    va_list list;
    int n = 0;

    va_start(list, format);
    for (int i = 0; format[i]; i++){
        if (format[i] == '%')
            flags(format[i + 1], &i, list, n);
        else {
            my_putchar(format[i]);
            n++;
        }
    }
    va_end(list);
    return n;
}
