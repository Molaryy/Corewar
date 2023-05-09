/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** champion
*/

#ifndef asm
    #define asm
    #include <stdio.h>
    #include "jb.h"

    typedef struct header_s {

        char *name;
        char *description;

    } header_t;

    typedef struct body_s {

        char label_char;
        char *hexa;
        char *name;
        size_t nb_param;
        bool reg;
        bool direct;
        bool indirect;

    } body_t;

/**
 * @brief detects if the file has the correct extension
 *
 * @param filepath
 * @return true
 * @return false
 */
bool detect_file_extension(char const *filepath);
#endif /* !asm */
