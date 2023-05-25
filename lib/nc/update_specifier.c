/*
** EPITECH PROJECT, 2022
** update specifier
** File description:
** This will update the specifiers of the printf function
*/

#include <stdlib.h>

#include "nc.h"

void update_specifier_flag(update_specifier_t *spec_st_up)
{
    specifier_t *specifier = &((*spec_st_up).specifier);
    str_ll_t **specifier_str = &((*spec_st_up).specifier_str);
    int *i = &((*spec_st_up).i);

    if (*specifier_str == NULL)
        return;
    if ((*specifier_str)->c == '0' || (*specifier_str)->c == '#' ||
        (*specifier_str)->c == '+' || (*specifier_str)->c == '-' ||
        (*specifier_str)->c == ' ') {
        (*specifier).flag = (*specifier_str)->c;
        (*specifier_str) = (*specifier_str)->next;
        (*i)++;
    }
}

void update_specifier_min_width(update_specifier_t *specifier_m,
    va_list arguments)
{
    specifier_t *specifier = &((*specifier_m).specifier);
    str_ll_t **specifier_str = &((*specifier_m).specifier_str);
    int *i = &((*specifier_m).i);
    char *format = (*specifier_m).format;

    if (*specifier_str == NULL)
        return;
    if ((*specifier_str)->c >= '1' && (*specifier_str)->c <= '9') {
        (*specifier).min_width = my_getnbr_printf(format, *i);
        *specifier_str = iterate_n(*specifier_str,
            my_log((*specifier).min_width, 10) + 1);
        (*i) += my_log((*specifier).min_width, 10) + 1;
    } else if ((*specifier_str)->c == '*') {
        (*specifier).min_width = va_arg(arguments, int);
        *specifier_str = (*specifier_str)->next;
        (*i)++;
    }
}

void handle_precision(update_specifier_t *specifier_m,
    va_list arguments)
{
    specifier_t *specifier = &((*specifier_m).specifier);
    str_ll_t **specifier_str = &((*specifier_m).specifier_str);
    int *i = &((*specifier_m).i);
    char *format = (*specifier_m).format;

    if ((*specifier_str)->c >= '0' && (*specifier_str)->c <= '9') {
        (*specifier).precision = my_getnbr_printf(format, *i);
        *specifier_str = iterate_n(*specifier_str,
            my_log((*specifier).precision, 10) + 1);
        *i += my_log((*specifier).precision, 10) + 1;
        return;
    }
    if ((*specifier_str)->c == '*') {
        (*specifier).precision = va_arg(arguments, int);
        *specifier_str = (*specifier_str)->next;
        (*i)++;
    }
}

void update_specifier_precision(update_specifier_t *specifier_m,
    va_list arguments)
{
    specifier_t *specifier = &((*specifier_m).specifier);
    str_ll_t **specifier_str = &((*specifier_m).specifier_str);
    int *i = &((*specifier_m).i);
    char *format = (*specifier_m).format;

    if (*specifier_str == NULL)
        return;
    if ((*specifier_str)->c == '.') {
        *specifier_str = (*specifier_str)->next;
        (*i)++;
        handle_precision(specifier_m, arguments);
    }
}

void update_specifier_length_modifier(update_specifier_t *specifier_m,
    va_list arguments)
{
    specifier_t *specifier = &((*specifier_m).specifier);
    str_ll_t **specifier_str = &((*specifier_m).specifier_str);
    int *i = &((*specifier_m).i);
    char *format = (*specifier_m).format;

    if (*specifier_str == NULL)
        return;
    if ((*specifier_str)->c == 'h' || (*specifier_str)->c == 'l' ||
        (*specifier_str)->c == 'L') {
        ((*specifier).length_modifier)[0] = (*specifier_str)->c;
        *specifier_str = (*specifier_str)->next;
        (*i)++;
        if ((*specifier_str)->c == 'h' || (*specifier_str)->c == 'l' ||
            (*specifier_str)->c == 'L') {
            ((*specifier).length_modifier)[1] = (*specifier_str)->c;
            *specifier_str = (*specifier_str)->next;
            (*i)++;
        }
    }
}
