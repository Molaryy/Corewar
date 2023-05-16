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
    #include "parser.h"
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

    typedef struct file_s {

        char **origin_file;
        char **parsing_file;
        header_t *header;
        body_t *body;

    } file_t;

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
size_t compiler(char *filepath);

/**
 * @brief check if both structure body_t and header_t are properly initialize
 *
 * @param body
 * @param header
 * @return true
 * @return false
 */
bool init_compiler(file_t *file);

/**
 * @brief take the filepath and transform into char**
 *
 * @param filepath
 * @return char**
 */
char **get_file(char *filepath);

/**
 * @brief function to free all the parameter
 *
 * @param file
 * @param parser
 */
void free_header(file_t *file, parser_t *parser);

/**
 * @brief destroy parser
 * @param pars
 */
void destroy_parser(parser_t *pars);
#endif /* !asm_h_ */
