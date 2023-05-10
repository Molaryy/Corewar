/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** champion
*/

#ifndef asm_h_
    #define asm_h_
    #include <stdio.h>
    #include "jb.h"
    #include <sys/stat.h>
    #include <sys/types.h>
    #include <fcntl.h>
    #define FAILURE 84
    #define SUCCESS 0

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

/**
 * @brief pricipal function of the compiler
 * @param filepath char const *
 * @return size_t
 */
size_t compiler(char const *filepath);

/**
 * @brief check if both structure body_t and header_t are properly initialize
 *
 * @param body
 * @param header
 * @return true
 * @return false
 */
bool init_compiler(body_t *body, header_t *header);
#endif /* !asm_h_ */
