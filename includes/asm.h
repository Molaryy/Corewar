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
    #include "link.h"
    #include "parser.h"
    #include <sys/stat.h>
    #include <sys/types.h>
    #include <fcntl.h>
    #define FAILURE 84
    #define SUCCESS 0
    #define MEM_SIZE                (6 * 1024)
    #define IDX_MOD                 512
    #define MAX_ARGS_NUMBER         4

    #define COMMENT_CHAR            '#'
    #define LABEL_CHAR              ':'
    #define DIRECT_CHAR             '%'
    #define SEPARATOR_CHAR          ','

    #define LABEL_CHARS             "abcdefghijklmnopqrstuvwxyz_0123456789"

    #define NAME_CMD_STRING         ".name"
    #define COMMENT_CMD_STRING      ".comment"

    typedef struct header_s {

        char *name;
        char *description;

    } header_t;

    typedef struct body_s {

        char **bodyArray;
        link_t *labels;

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
 * @brief fonction to check if line is equal to a commentary
 *
 * @param line
 * @return true
 * @return false
 */
bool is_commentary(char *line);

/**
 * @brief function to check if line is equal to a name
 *
 * @param line
 * @return true
 * @return false
 */
bool is_name(char *line);

/**
 * @brief function to check if line is equal to a description
 *
 * @param line
 * @return true
 * @return false
 */
bool is_description(char *line);

/**
 * @brief function that check if the number of arg is correct
 *
 * @param array
 * @param max
 * @return true
 * @return false
 */
bool check_nb_arg(char **array, size_t max);

/*
 * @brief destroy parser
 * @param pars
 */
void destroy_parser(parser_t *pars);

/**
 * @brief get body
 * @param filepath
 */
bool parse_body(file_t *file, char *filepath);

/**
 * @brief free body structure
 *
 * @param file
 */
void free_body(file_t *file);

/**
 * @brief check the number of params in a instruction
 *
 * @param file
 * @param pars
 * @return true
 * @return false
 */
bool check_instruction_number_arguments(body_t *body, parser_t *pars);

/**
 * @brief check the types in the arguments
 *
 * @param body
 * @param pas
 * @return true
 * @return false
 */
bool check_type_arguments(char **line, parser_t *pars, size_t start);

/**
 * @brief Get the number params object
 *
 * @param instruction
 * @param pars
 * @return size_t
 */
size_t get_number_params(char *instruction, parser_t *pars);

/**
 * @brief add labels name to link
 *
 * @param body
 * @return true
 * @return false
 */
bool add_labels_to_link(body_t *body);
#endif /* !asm_h_ */
