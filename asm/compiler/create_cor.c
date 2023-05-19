/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** create cor file
*/

#include "asm.h"

extern void in_another_file(char const *filename, char *filepath)
{
    char *slash = NULL;
    if (filename != NULL) {
        slash = my_strchr(filepath, '/');
        if (slash != NULL) {
            q_strcpy(filepath, slash + 1);
        }
    }
}

extern char* create_cor_file(const char* str)
{
    const char* filename = my_strchr(str, '/');
    const char* extension = ".cor";
    int filename_length = (filename != NULL) ? my_strlen(filename + 1)
                        : my_strlen(str);
    int filepath_length = filename_length + my_strlen(extension) + 1;
    char* filepath = malloc(filepath_length);
    char* dot = NULL;

    if (filepath == NULL)
        exit(84);
    if (filename != NULL)
        q_strcpy(filepath, filename + 1);
    else
        q_strcpy(filepath, str);
    dot = my_strchr(filepath, '.');
    if (dot != NULL)
        *dot = '\0';
    in_another_file(filename, filepath);
    q_strcat(filepath, extension);
    return filepath;
}

extern void cor_file(char *filepath)
{
    char *filename = create_cor_file(filepath);
    printf("%s\n", filename);
}
