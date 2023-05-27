/*
** EPITECH PROJECT, 2023
** corewar/src/process/helper.c
** File description:
** helper functions used for the processes
*/

#include "core.h"

process_t process_create_null(void)
{
    process_t process = {0};

    process.pc = -1;
    process.carry = 0;
    process.cycle = 0;
    process.alive = 1;
    for (int j = 0; j < REG_NUMBER; j++)
        set_32uint(0, process.registers[j].byte);
    return process;
}
