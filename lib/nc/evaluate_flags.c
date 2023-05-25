/*
** EPITECH PROJECT, 2022
** Evaluate Flags
** File description:
** This will evaluate the flags from the the string
*/

#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "nc.h"
#include "flags.h"

int my_put_science(va_list arguments, int *char_count, specifier_t specifier);
int my_put_float_ll(va_list arguments, int *char_count, specifier_t specifier);
int flag_g(va_list arguments, int *count_char, specifier_t specifier);
void my_put_unsigned_int(unsigned int n, int *char_count);
str_ll_t * my_ll_add(str_ll_t * current_node, char ch);
int my_putstr_printf(va_list arguments, int *count, specifier_t specifier);
int my_put_nbr_printf(va_list arguments, int *char_count,
    specifier_t specifier);
specifier_t error_struct(void);
void update_specifier_flag(update_specifier_t *specifier_m);
void update_specifier_min_width(update_specifier_t *specifier_m,
    va_list arguments);
void update_specifier_precision(update_specifier_t *specifier_m,
    va_list arguments);
void update_specifier_length_modifier(update_specifier_t *specifier_m,
    va_list arguments);
str_ll_t *iterate_n(str_ll_t *str, int n);
char get_last_ll(str_ll_t *str);
str_ll_t *iterate_ll(str_ll_t *node, int i);
int free_str_ll(str_ll_t *node);
void error_specifier_m(update_specifier_t *specifier_m);
void error_output(str_ll_t **specifier, int *char_count);
int is_valid_conversion_specifier(char c);
int my_putchar_printf_c(va_list arguments, int *char_count,
    specifier_t specifier);
int my_convert_octal(va_list arguments, int *char_count, specifier_t specifier);
char *init_length_modifier(void);
specifier_t null_specifier(void);

static const flag_t flags[] = {
    {.flag = 's', .used_func = my_putstr_printf},
    {'d', my_put_nbr_printf},
    {'i', my_put_nbr_printf},
    {'f', my_put_float_ll},
    {'e', my_put_science},
    {'E', my_put_science},
    {'c', my_putchar_printf_c},
    {'g', flag_g},
    {'G', flag_g},
    {'p', my_pointers_hexa},
    {'x', my_convert_hexa},
    {'X', my_convert_hexa},
    {'o', my_convert_octal},
    {'u', my_put_nbr_printf_unsigned}
};

const flag_t *get_flag(char c)
{
    for (size_t i = 0; i < sizeof(flags) / sizeof(*flags); i++) {
        if (flags[i].flag == c)
            return &flags[i];
    }
    return NULL;
}

void populate_ll_specifier(update_specifier_t *specifier_m)
{
    str_ll_t *specifier = NULL;
    char c;
    int *i = &((*specifier_m).i);
    char *format = (*specifier_m).format;

    (*i)++;
    c = format[*i];
    while (!(c == 's' || c == 'd' || c == 'i' || c == 'f' || c == 'e' ||
        c == 'E' || c == 'c' || c == 'g' || c == 'G' || c == 'p' ||
        c == 'x' || c == 'X' || c == 'o' || c == 'u')
        && c != '%' && c != '\0' && c != '\n') {
        specifier = my_ll_add(specifier, c);
        (*i)++;
        c = format[*i];
    }
    if (c != '\0')
        specifier = my_ll_add(specifier, c);
    (*specifier_m).specifier_str = specifier;
}

specifier_t update_specifier(update_specifier_t *specifier_m, va_list arguments)
{
    str_ll_t **specifier_str = &((*specifier_m).specifier_str);
    str_ll_t *backup_flags = (*specifier_m).specifier_str;
    int start_i;
    int *i = &((*specifier_m).i);

    (*i) -= my_list_size(*specifier_str) - 1;
    start_i = *i;
    update_specifier_flag(specifier_m);
    update_specifier_min_width(specifier_m, arguments);
    update_specifier_precision(specifier_m, arguments);
    update_specifier_length_modifier(specifier_m, arguments);
    if ((*specifier_str) == NULL)
        return specifier_m->specifier;
    if (is_valid_conversion_specifier((*specifier_str)->c) == 1) {
        (specifier_m->specifier).conversion_specifier = (*specifier_str)->c;
    } else {
        (*specifier_m).specifier_str = iterate_ll(backup_flags, *i - start_i);
        error_specifier_m(specifier_m);
    }
    return (specifier_m->specifier);
}

specifier_t parse_flags(update_specifier_t *specifier_m, va_list arguments)
{
    str_ll_t **specifier = &(specifier_m->specifier_str);
    char c;
    specifier_t *specifier_val = &(specifier_m->specifier);
    int *i = &(specifier_m->i);
    int *char_count = &(specifier_m->char_count);
    char *length_modifier = init_length_modifier();

    (*specifier_val) = init_specifier_t();
    (*specifier_val).length_modifier = length_modifier;
    populate_ll_specifier(specifier_m);
    *specifier_val = update_specifier(specifier_m, arguments);
    if ((*specifier_val).min_width == -300 &&
        (*specifier_val).precision == -300) {
        error_output(specifier, char_count);
        free(length_modifier);
        return null_specifier();
    }
    return *specifier_val;
}

int evaluate_flags(update_specifier_t *specifier_m, va_list arguments)
{
    int error = 0;
    specifier_t specifier;
    int *char_count = &(specifier_m->char_count);

    specifier = parse_flags(specifier_m, arguments);
    if (specifier.conversion_specifier == '%') {
        my_putchar_printf('%', char_count);
        return error;
    }
    if (specifier.conversion_specifier != '\0') {
        if (specifier.conversion_specifier == 'n')
            *(va_arg(arguments, int*)) = (*specifier_m).char_count;
        else {
            error = get_flag(specifier.conversion_specifier
                )->used_func(arguments,
                &((*specifier_m).char_count), specifier);
        }
    }
    return error;
}
