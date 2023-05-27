/*
** EPITECH PROJECT, 2023
** corewar/src/vm/init.c
** File description:
** initializers for vm struct
*/

#include "core.h"

void init_vm(info_corewar_t *info)
{
    info->vm.memory = init_memory(info);
}
