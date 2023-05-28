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
    free(buffer);
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
    file.file_content = malloc(sizeof(char) * ((int)file.file_size));
    if (!file.file_content) {
        file.file_size = (size_t) -1;
        return file;
    }
    read(fd, file.file_content, file.file_size);
    close(fd);
    return file;
}

int get_address(int num_champ, int champ_index, int arr_len)
{
    return (arr_len / num_champ + 1) * champ_index;
}

int get_num_champs(int argc, char **argv)
{
    int res = 0;

    for (int i = 0; i < argc; i++)
        if (is_file(argv[i]) == TRUE)
            res++;
    return res;
}
