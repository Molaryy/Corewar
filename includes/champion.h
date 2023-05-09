/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** champion
*/

#ifndef champion
    #define champion
    #include <stdio.h>

    typedef struct header_s {

        char *name;
        char *description;

    }header_t;

    typedef struct body_s {

        char label_char;
        char *hexa;
        char *name;
        size_t nb_param;
        bool reg;
        bool direct;
        bool indirect;

    } body_t;


#endif /* !champion */
