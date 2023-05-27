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

    info.cursors = cursor_create();
    display_info(&info);
    init_vm(&info);
    cursor_delete(info.cursors);
    stop(&info, 0);
}
