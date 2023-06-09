/*
** EPITECH PROJECT, 2023
** PROJECT
** File description:
** check_params
*/

#include "jb.h"
#include "asm.h"

static size_t check_value(char *name, size_t valueToReturn, size_t pos)
{
    if ((my_strcmp(name, "ld")) && valueToReturn != 0)
        valueToReturn = 1;
    if (my_strcmp(name, "lld") && valueToReturn != 0)
        valueToReturn = 1;
    if (my_strcmp(name, "and") && (pos == 1 || pos == 2))
        valueToReturn = 2;
    if (my_strcmp(name, "or") && (pos == 1 || pos == 2))
        valueToReturn = 2;
    if (my_strcmp(name, "xor") && (pos == 1 || pos == 2))
        valueToReturn = 2;
    if (my_strcmp(name, "ldi") && (pos == 1 || pos == 2))
        valueToReturn = 2;
    if (my_strcmp(name, "sti") && (pos == 2 || pos == 3))
        valueToReturn = 2;
    if (my_strcmp(name, "lldi") && (pos == 1 || pos == 2))
        valueToReturn = 2;
    return valueToReturn;
}

extern size_t get_type(char c, char *name, size_t pos)
{
    size_t valueToReturn = 9999;
    char *instructions[] = {"live", "zjmp", "fork", "lfork", NULL};

    switch (c) {
        case 'r': valueToReturn = 0; break;
        case '%': valueToReturn = 2; break;
        case '-': valueToReturn = 2; break;
        default: valueToReturn = 2; break;
    }
    for (size_t i = 0; instructions[i]; i++) {
        if (my_strcmp(name, instructions[i]) && valueToReturn != 0)
            valueToReturn = 1;
    }
    if (my_strcmp(name, "st") && pos == 2)
        valueToReturn = 2;
    valueToReturn = check_value(name, valueToReturn, pos);
    return valueToReturn;
}
