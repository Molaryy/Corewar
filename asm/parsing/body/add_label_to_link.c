/*
** EPITECH PROJECT, 2023
** PROJECT
** File description:
** add_label_to_link
*/

#include "asm.h"
#include "link.h"

static void count_repetitions(char *data, char *label, size_t *count)
{
    if (my_strcmp(data, label))
        *count += 1;
}

static bool check_repetition_label(body_t *body)
{
    size_t count = 0;
    link_t *link = body->labels;
    link_t *tmp = body->labels;

    for (; body->labels; body->labels = body->labels->next) {
        for (; link ; link = link->next)
            count_repetitions(body->labels->data, link->data, &count);
        link = tmp;
        if (count > 1)
            return false;
        count = 0;
    }
    return true;
}

extern bool add_labels_to_link(body_t *body, file_t *file)
{
    char **pars = NULL;

    for (size_t i = 0; body->bodyArray[i]; i++) {
        if (!(pars = str_to_array_separator(body->bodyArray[i], "\t ")))
            return false;
        if (pars[0][my_strlen(pars[0]) - 1] != ':')
            continue;
        if (!body->labels)
            body->labels = create_link(body->labels, my_strcpy(pars[0]));
        else
            add_link_end(&body->labels, my_strcpy(pars[0]));
        free_array_str(pars);
    }
    if (!check_repetition_label(body)) {
        free_links(&(body->labels));
        return false;
    }
    file->nbLabels = listlen(body->labels);
    free_links(&(body->labels));
    return true;
}
