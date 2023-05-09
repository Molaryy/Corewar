/*
** EPITECH PROJECT, 2022
** LINK
** File description:
** LINK.h
*/

#ifndef LINK_H_
    #define LINK_H_
    #include <unistd.h>
    #include <stdlib.h>
    #include "jb.h"

typedef struct link_s {

    struct link_s *next;
    struct link_s *prev;
    void *data;
} link_t;

/**
 * @brief add link to end
 *
 * @param link
 * @param data
 */
void add_link_end(link_t **link, void *data);

/**
 * @brief Create a list object
 *
 * @param node
 * @param data
 * @return link_t*
 */
link_t *create_link(link_t *node, void *data);

/**
 * @brief free all the links
 *
 * @param link link_t *
 */
void free_links(link_t **head_ref);

/**
 * @brief link len
 *
 * @param link
 * @return size_t
 */
size_t link_len(link_t *link);

/**
 * @brief delete any node in the middle
 *
 * @param link
 * @param position
 */
link_t *delete_mid_node(link_t *link, size_t position);

/**
 * @brief delete first node
 *
 * @param node
 */
void link_rm_beg_node(link_t **node);

/**
 * @brief print linked list string
 * @param link
 */
void print_str_link(link_t *link);
#endif /* LINK_H_ */
