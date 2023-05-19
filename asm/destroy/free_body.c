/*
** EPITECH PROJECT, 2023
** PROJECT
** File description:
** free_body
*/

#include "asm.h"
#include "jb.h"

extern void free_body(file_t *file)
{
    free_array_str(file->body->bodyArray);

    for (size_t i = 0; i < file->nbLinesBody; i++) {
        if (file->champ[i].label)
            free(file->champ[i].label);
        if (file->champ[i].paramName)
            free(file->champ[i].paramName);
        free_array_str(file->champ[i].params);
    }
}
