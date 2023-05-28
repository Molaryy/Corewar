/*
** EPITECH PROJECT, 2023
** PROJECT
** File description:
** main
*/

#include "core.h"

int main(int ac, char **av)
{
    info_corewar_t info = parse_args(ac, av);

    init_vm(&info);
    run_vm(&info);
    stop(&info, 0);
}
