/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** create byte
*/

#include "asm.h"

extern parambyte_t *create_param_byte(const char* param, file_t *file, int i)
{
    parambyte_t *paramByte = malloc(sizeof(parambyte_t));
    unsigned int value = 0;
    if (param[0] == '%') {
        file->offset += 4;
        if (param[1] != ':') {
            value = get_value(param, 1);
            paramByte->bytes = get_direct_bytes(value, paramByte);
        } else {
            value = one_label_handling(param, file, value, i);
            paramByte->bytes = get_direct_bytes(value, paramByte);
        }
    } else if (param[0] == 'r') {
        register_go(file, paramByte, param, value);
    } else {
        file->offset += 4;
        value = get_value(param, 2);
        paramByte->bytes = get_indirect_bytes(value, paramByte);
    }
    return paramByte;
}

extern parambyte_t *create_zjmp_bytes(const char *param, file_t *file, int i)
{
    parambyte_t *paramByte = malloc(sizeof(parambyte_t));
    int value = 0;

    if (paramByte == NULL)
        exit(EXIT_FAILURE);
    if (param[0] == '%')
        if (param[1] != ':')
            value = get_value(param, 1);
        else
            value = one_label_handling(param, file, value, i);
    else
        value = get_value(param, 2);
    file->offset += 2;
    paramByte->bytes = get_indirect_bytes(value, paramByte);
    return paramByte;
}

extern parambyte_t *create_ldi_bytes(const char *param, file_t *file, int i)
{
    parambyte_t *paramByte = malloc(sizeof(parambyte_t));
    unsigned int value = 0;
    if (param[0] == '%') {
        file->offset += 2;
        if (param[1] != ':') {
            value = get_value(param, 1);
            paramByte->bytes = get_indirect_bytes(value, paramByte);
        } else {
            value = one_label_handling(param, file, value, i);
            paramByte->bytes = get_indirect_bytes(value, paramByte);
        }
    } else if (param[0] == 'r') {
        register_go(file, paramByte, param, value);
    } else {
        file->offset += 2;
        value = get_value(param, 2);
        paramByte->bytes = get_indirect_bytes(value, paramByte);
    }
    return paramByte;
}

extern parambyte_t *create_sti_bytes(const char *param, file_t *file, int i)
{
    parambyte_t *paramByte = malloc(sizeof(parambyte_t));
    unsigned int value = 0;
    if (param[0] == '%') {
        file->offset += 2;
        if (param[1] != ':') {
            value = get_value(param, 1);
            paramByte->bytes = get_indirect_bytes(value, paramByte);
        } else {
            value = one_label_handling(param, file, value, i);
            paramByte->bytes = get_indirect_bytes(value, paramByte);
        }
    } else if (param[0] == 'r') {
        register_go(file, paramByte, param, value);
    } else {
        file->offset += 2;
        value = get_value(param, 2);
        paramByte->bytes = get_indirect_bytes(value, paramByte);
    }
    return paramByte;
}

extern parambyte_t *create_fork_bytes(const char *param, file_t *file, int i)
{
    parambyte_t *paramByte = malloc(sizeof(parambyte_t));
    unsigned int value = 0;

    if (paramByte == NULL)
        exit(EXIT_FAILURE);
    if (param[0] == '%')
        if (param[1] != ':') {
            value = get_value(param, 1);
        } else
            value = one_label_handling(param, file, value, i);
    else
        value = get_value(param, 2);
    file->offset += 2;
    paramByte->bytes = get_indirect_bytes(value, paramByte);
    return paramByte;
}
