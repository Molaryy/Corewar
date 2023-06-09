/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** label_find
*/

#include "asm.h"

extern void label_find(file_t *file)
{
    int k = 0;
    size_t i;

    file->label_find = malloc(sizeof(label_find_t) * file->nbLabels);
    file->header->prog_size = 0;

    for (i = 0; i != file->nbLinesBody; i++) {
        if (file->champ[i].label ) {
            file->label_find[k].adresse = file->header->prog_size;
            file->label_find[k].name = file->champ[i].label;
            file->label_find[k].name =
                    remove_char(file->label_find[k].name, ':');
            k++;
        }
        if (file->champ[i].paramName && starting_prog_size(file, i)) {
            continue;
        }
    }
}

extern unsigned int one_label_handling(const char *param, file_t *file,
                                unsigned int value, int k)
{
    param = remove_char(param, '%');
    param = remove_char(param, ':');
    for (size_t i = 0; i != file->nbLabels; i++)
        if (my_strcmp(param, file->label_find[i].name))  {
            value = (file->label_find[i].adresse - file->champ[k].offset + 1);
        }
    return value;
}
