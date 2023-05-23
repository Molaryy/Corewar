/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** create byte
*/

#include "asm.h"

extern parambyte_t *create_param_byte(const char* param)
{
    parambyte_t *paramByte = malloc(sizeof(parambyte_t));
    unsigned int value = 0;

    if (paramByte == NULL)
        exit(EXIT_FAILURE);
    if (param[0] == 'r') {
        value = get_value(param, 0);
        paramByte->bytes = get_register_bytes(value, paramByte);
    } else if (param[0] == '%' && param[1] != ':') {
        value = get_value(param, 1);
        paramByte->bytes = get_direct_bytes(value, paramByte);
    } else {
        value = get_value(param, 2);
        paramByte->bytes = get_indirect_bytes(value, paramByte);
    }
    return paramByte;
}

extern parambyte_t *create_zjmp_bytes(const char *param)
{
    parambyte_t *paramByte = malloc(sizeof(parambyte_t));
    unsigned int value = 0;

    if (paramByte == NULL)
        exit(EXIT_FAILURE);
    if (param[0] == '%')
        value = get_value(param, 1);
    else
        value = get_value(param, 2);
    paramByte->bytes = get_indirect_bytes(value, paramByte);
    return paramByte;
}

extern parambyte_t *create_ldi_bytes(const char *param, int i)
{
    parambyte_t *paramByte = malloc(sizeof(parambyte_t));
    unsigned int value = 0;

    if (paramByte == NULL)
        exit(EXIT_FAILURE);
    if (param[0] == '%') {
        value = get_value(param, 1);
        paramByte->bytes = get_indirect_bytes(value, paramByte);
    } else if (param[0] == 'r') {
        value = get_value(param, 0);
        paramByte->bytes = get_register_bytes(value, paramByte);
    } else {
        value = get_value(param, 2);
        paramByte->bytes = get_indirect_bytes(value, paramByte);
    }
    if (i == 2) {
        value = get_value(param, 0);
        paramByte->bytes = get_register_bytes(value, paramByte);
    }
    return paramByte;
}

extern parambyte_t *create_sti_bytes(const char *param, int i)
{
    parambyte_t *paramByte = malloc(sizeof(parambyte_t));
    unsigned int value = 0;

    if (paramByte == NULL)
        exit(EXIT_FAILURE);
    if (param[0] == '%') {
        value = get_value(param, 1);
        paramByte->bytes = get_indirect_bytes(value, paramByte);
    } else if (param[0] == 'r') {
        value = get_value(param, 0);
        paramByte->bytes = get_register_bytes(value, paramByte);
    } else {
        value = get_value(param, 2);
        paramByte->bytes = get_indirect_bytes(value, paramByte);
    }
    if (i == 0) {
        value = get_value(param, 0);
        paramByte->bytes = get_register_bytes(value, paramByte);
    }
    return paramByte;
}

extern parambyte_t *create_fork_bytes(const char *param)
{
    parambyte_t *paramByte = malloc(sizeof(parambyte_t));
    unsigned int value = 0;

    if (paramByte == NULL)
        exit(EXIT_FAILURE);
    if (param[0] == '%')
        value = get_value(param, 1);
    else
        value = get_value(param, 2);
    paramByte->bytes = get_indirect_bytes(value, paramByte);
    return paramByte;
}
