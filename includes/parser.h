/*
** EPITECH PROJECT, 2023
** PROJECT
** File description:
** parser.h
*/

#ifndef PARSER_H_
    #define PARSER_H_
    #define NB_INSTRIUCTIONS 14

    typedef struct parser_s {

        char *name;
        size_t nb_params;
        size_t p3;
        size_t p1;
        size_t p2;

    } parser_t;

/**
 * @brief inits the parser struct to get
 * @param filepath
 * @return
 */
parser_t *init_parser_reference(char *filepath);
#endif /*PARSER_H_*/
