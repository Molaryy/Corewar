/*
** EPITECH PROJECT, 2023
** include
** File description:
** cursor.h
*/

#ifndef CURSOR_H_
    #define CURSOR_H_

typedef struct cursor_node_s {
    long long position;
    int nb_cycle;
    struct cursor_node_s *next;
    struct cursor_node_s *prev;
} cursor_node_t;

typedef struct cursor_s {
    cursor_node_t *first;
    cursor_node_t *end;
    unsigned int size;
} cursor_t;

/**
 * @brief Create a chain list of cursor
 *
 * @return cursor_t *
 */
cursor_t *cursor_create(void);

/**
 * @brief Add a cursor node
 *
 * @param list cursor_t *
 * @param position the position in memory of the cursor
 * @param nb_cycle his nb_cycle
 */
void cursor_add(cursor_t *list, long long position, int nb_cycle);

/**
 * @brief Remove the first element of cursor_t *
 *
 * @param list cursor_t *
 */
void cursor_remove(cursor_t *list);

/**
 * @brief Remove a cursor with a position given
 *
 * @param list cursor_t *
 * @param position long long which is the position in memory
 */
void cursor_remove_pos(cursor_t *list, long long position);

/**
 * @brief Delete a list of cursor
 *
 * @param list cursor_t *
 */
void cursor_delete(cursor_t *list);

#endif /* CURSOR_H_ */