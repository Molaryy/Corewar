/*
** EPITECH PROJECT, 2023
** PROJECT
** File description:
** parse_txt_file
*/

#include "jb.h"
#include "asm.h"
#include "parser.h"

static char **get_file(char const *filepath)
{
    int FD = open(filepath, O_RDONLY);
    char *buffer = NULLL;
    char **fileTab = NULL;
    struct stat info;

    if (stat(filepath, &info) == -1)
        return false;
    buffer = malloc(sizeof(char) * (info.st_size + 1));
    if (!buffer)
        return false;
    buffer[info.st_size] = '\0';
    if (read(fd, filepath, info.st_size) == -1)
        return false;
    fileTab =
    close(FD);
}
