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

    for (; tmp; tmp = tmp->next) {
        for (; link ; link = link->next)
            count_repetitions(tmp->data, link->data, &count);
        if (count > 1)
            return false;
        count = 0;
    }
    return true;
}

static bool is_label_alphanumeric(link_t *link, file_t *file)
{
    link_t *tmp = link;
    char *label = NULL;

    if (!link)
        return false;
    for (; tmp; tmp = tmp->next) {
        if (!(label = my_strcpy(tmp->data)))
            return false;
        label[my_strlen(label) - 1] = '\0';
        if (!is_str_alphanumeric(label)){
            return false;
        }
    }
    file->nbLabels = link_len(link);
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
    if (!is_label_alphanumeric(body->labels, file))
        return false;
    return true;
}
