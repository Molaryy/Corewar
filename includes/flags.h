/*
** EPITECH PROJECT, 2022
** flags struct
** File description:
** This will create a structure for all the flags
*/

#include <stdarg.h>

#include "str_linked_list.h"

#ifndef _FLAG_H__
    #define _FLAG_H__

typedef struct {
    char flag;
    int min_width;
    int precision;
    char *length_modifier;
    char conversion_specifier;
} specifier_t;

typedef struct {
    char flag;
    int (*used_func)(va_list list, int *char_count, specifier_t specifier);
} flag_t;

typedef struct {
    specifier_t specifier;
    str_ll_t *specifier_str;
    char *format;
    int i;
    int char_count;
    int error;
} update_specifier_t;

#endif
