/*
** EPITECH PROJECT, 2023
** corewar/src/helper/get.c
** File description:
** getter functions
*/

#include "core.h"

size_t get_file_size(char *filename)
{
    struct stat file_info;

    if (stat(filename, &file_info) < 0) {
        return -1;
    }
    return file_info.st_size;
}

char *get_file_content(char *filename)
{
    int fd = open(filename, O_RDONLY);
    struct stat file_info;
    char *buffer;

    if (fd < 0 || stat(filename, &file_info) < 0) {
        close(fd);
        return NULL;
    }
    buffer = malloc(sizeof(char) * (file_info.st_size + 1));
    buffer[file_info.st_size] = '\0';
    read(fd, buffer, file_info.st_size);
    close(fd);
    return buffer;
}
