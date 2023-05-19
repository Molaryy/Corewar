/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** create cor file
*/

#include "asm.h"

extern char* my_strchr(const char* __first_str, char index)
{
    while (*(__first_str) != '\0') {
        if (*(__first_str) == index)
            return ((char*)__first_str);
        __first_str++;
    }
    if (*(__first_str) == index) {
        return ((char*)__first_str);
    }
    return NULL;
}

extern char *q_strcpy(char *dest, char const *src)
{
    int a = 0;

    while (src[a] != '\0') {
        dest[a] = src[a];
        a++;
    }
    dest[a] = '\0';
    return (dest);
}

char* create_cor_file(const char* str)
{
    const char* filename = my_strchr(str, '/');
    const char* extension = ".cor";
    int filename_length = (filename != NULL) ? my_strlen(filename + 1) : my_strlen(str);
    int filepath_length = filename_length + my_strlen(extension) + 1;
    char* dot = NULL;
    char* filepath = malloc(filepath_length);

    if (filepath == NULL)
        return NULL;
    if (filename != NULL) {
        q_strcpy(filepath, filename + 1);
        dot = my_strchr(filepath, '.');
        if (dot != NULL)
            *dot = '\0';
    } else {
        q_strcpy(filepath, str);
    }
    filepath = strcat(filepath, extension);
    return filepath;
}


void cor_file(char *filepath)
{
    char *filename = create_core_file(filepath);
    printf("%s\n", filename);
}