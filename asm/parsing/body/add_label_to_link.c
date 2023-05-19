/*
** EPITECH PROJECT, 2023
** PROJECT
** File description:
** add_label_to_link
*/

#include "asm.h"

static bool check_repetition_label(body_t *body)
{
    for (; body->labels; body->labels = body->labels->next) {
            
    }
}

bool add_labels_to_link(body_t *body)
{
    char **pars = NULL;

    for (size_t i = 0; body->bodyArray[i]; i++) {
        if (!(pars = str_to_array_separator(body->bodyArray[i], "\t ")))
            return false;
        if (pars[0][my_strlen(pars[0]) - 1] != ':')
            continue;
        if (!body->labels)
            body->labels = create_link(body->labels, pars[0]);
        else
            add_link_end(&body->labels, pars[0]);
        free_array_str(pars);
    }
    return true;
}
