/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main.c
*/

#include "jb.h"
#include "asm.h"

int main(int ac, char **av)
{
    if (ac != 2)
        return FAILURE;
    return compiler(av[1]);
}
