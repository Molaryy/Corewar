/*
** EPITECH PROJECT, 2023
** corewar/src/helper/misc.c
** File description:
** miscallaneous helper functions
*/

#include "core.h"

int is_file(const char *filename)
{
    int fd = open(filename, O_RDONLY);

    if (fd < 0)
        return FALSE;
    close(fd);
    return TRUE;
}
