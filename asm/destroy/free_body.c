/*
** EPITECH PROJECT, 2023
** PROJECT
** File description:
** free_body
*/

#include "asm.h"
#include "jb.h"

void free_body(file_t *file)
{
    free_array_str(file->body->body);
}
