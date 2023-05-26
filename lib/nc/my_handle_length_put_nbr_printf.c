/*
** EPITECH PROJECT, 2022
** my_handle_length_put_nbr_printf.c
** File description:
** this will handle all length modifiers for floag d and i
*/

#include <stdarg.h>
#include <stddef.h>

#include "flags.h"

long long int my_handle_length_put_nbr_printf(va_list arguments,
    specifier_t specifier)
{
    long long int nb = va_arg(arguments, long long int);
    char *length_modifier = specifier.length_modifier;

    if (length_modifier[0] == 'h' && length_modifier[1] == 'h')
        nb = (unsigned char) nb;
    if (length_modifier[0] == 'h' && length_modifier[1] == '\0')
        nb = (short int) nb;
    if (length_modifier[0] == 'l' && length_modifier[1] == '\0')
        nb = (long int) nb;
    if (length_modifier[0] == 'l' && length_modifier[1] == 'l')
        nb = (long long int) nb;
    if (length_modifier[0] == 'L' && length_modifier[1] == '\0')
        nb = (size_t) nb;
    if (length_modifier[0] == '\0' && length_modifier[1] == '\0')
        nb = (int) nb;
    return nb;
}
