/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** label_find
*/

#include "asm.h"

extern void if_label_exist(file_t *file, int *k, int i)
{
    if (!file->champ[i].paramName) {
        file->label_find[*k].adresse = file->header->prog_size;
        file->label_find[*k].name = file->champ[i].label;
    }
    file->label_find[*k].name = remove_char(file->label_find[*k].name, ':');
    *(k++);
}

extern void label_find(file_t *file)
{
    int k = 0;
    size_t i;

    file->label_find = malloc(sizeof(label_find_t) * file->nbLabels);
    file->header->prog_size = 0;

    for (i = 0; i != file->nbLinesBody; i++) {
        if (file->champ[i].label && !file->champ[i].paramName) {
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
                                unsigned int value)
{
    param = remove_char(param, '%');
    param = remove_char(param, ':');
    for (int i = 0; i != 2; i++)
        if (my_strcmp(param, file->label_find[i].name))  {
            value = (file->label_find[i].adresse - file->offset + 1);
            my_printf("adresse -> %d\n", file->label_find[i].adresse);
            my_printf("offset -> %d\n", file->offset);
        }
    return value;
}
