/*
** EPITECH PROJECT, 2022
** error_detection
** File description:
** file for error structure specifiers
*/

#include <stdlib.h>

#include "str_linked_list.h"
#include "flags.h"

int my_putchar_printf(const char c, int *count);
int my_put_ll(str_ll_t *head, int *char_count);
int free_str_ll(str_ll_t *node);

specifier_t error_struct(void)
{
    specifier_t error = {
        .flag = '\0',
        .min_width = -300,
        .precision = -300,
        .length_modifier = '\0',
        .conversion_specifier = '\0'
    };
    return error;
}

void error_specifier_m(update_specifier_t *specifier_m)
{
    (*specifier_m).error = -1;
    (*specifier_m).specifier.precision = -300;
    (*specifier_m).specifier.min_width = -300;
}

void error_output(str_ll_t **specifier, int *char_count)
{
    my_putchar_printf('%', char_count);
    if ((*specifier) != NULL)
        my_put_ll(*specifier, char_count);
    free_str_ll(*specifier);
}
