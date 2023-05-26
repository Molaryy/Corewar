/*
** EPITECH PROJECT, 2023
** corewar/src/helper/get.c
** File description:
** getter functions
*/

#include "core.h"

static size_t size_of_file(int fd)
{
    size_t len = 0;
    size_t res = 1;
    char *buffer = malloc(sizeof(char) * 2);

    if (!buffer)
        return 0;
    for (size_t i = 0; res > 0; i++) {
        res = read(fd, buffer, 2);
        len += res;
    }
    close(fd);
    return len;
}

file_t get_file_content(char *filename)
{
    file_t file = {0};
    int fd = open(filename, O_RDONLY);

    file.file_size = (size_t) -1;
    if (fd < 0)
        return file;
    file.file_size = size_of_file(fd);
    fd = open(filename, O_RDONLY);
    my_printf("file size: %d\n", (int) file.file_size);
    file.file_content = malloc(sizeof(char) * ((int)file.file_size));
    if (!file.file_content) {
        file.file_size = (size_t) -1;
        return file;
    }
    read(fd, file.file_content, file.file_size);
    close(fd);
    return file;
}
