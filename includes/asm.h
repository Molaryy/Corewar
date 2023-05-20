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

    #define FIRST_CHAR              file->origin_file[i][0]

    #define REGISTER 'r'
    #define DIRECT_VALUE '%'
    #define INDIRECT_VALUE is_digit(params[i][0])

    #define MAX_BYTES 4

    typedef char    args_type_t;
    #define T_REG           1
    #define T_DIR           2
    #define T_IND           4
    #define T_LAB           8

    typedef struct octet_s{

        unsigned char bytes[MAX_BYTES];

    } octet_t;

    typedef struct op_s {
        char *mnemonique;
        char nbr_args;
        char type[MAX_ARGS_NUMBER];
        char code;
        int nbr_cycles;
        char *comment;
    } op_t;

    extern  op_t    op_tab[];

    #define COREWAR_EXEC_MAGIC      0xea83f3
    #define PROG_NAME_LENGTH        128
    #define COMMENT_LENGTH          2048

    typedef struct header_s {

        int magic;
        char name[PROG_NAME_LENGTH + 1];
        char description[COMMENT_LENGTH + 1];
        int  prog_size;

    } header_t;

    typedef struct body_s {

        char **bodyArray;
        link_t *labels;

    } body_t;
    typedef struct champ_s {

        char *paramName;
        size_t nbParams;
        char *label;
        char **params;

    } champ_t;

    typedef struct file_s {

        char **origin_file;
        char **parsing_file;
        header_t *header;
        body_t *body;
        champ_t *champ;
        octet_t octet_bytes;
        size_t nbLinesBody;

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
bool init_compiler(file_t *file, parser_t *pars);

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

/**
 * @brief function to code in byte the parameter
 *
 * @param params
 * @param nbParams
 */
unsigned char coding_byte(char **params, size_t nbParams);

/**
 * @brief function to print byte
 *
 * @param byte
 */
void print_bits(unsigned char byte);

/**
 * @brief handle the cor file
 *
 * @param filepath
 */
void cor_file(char *filepath, file_t *file);

/**
 * @brief check folder for pathname
 *
 * @param filename
 * @param filepath
 */
extern void in_another_file(char const *filename, char *filepath);

/**
 * @brief Create a cor file from a .s file
 *
 * @param str
 * @return char*
 */
extern char* create_cor_file(const char* str);

/**
 * @brief get the instruction byte value
 *
 * @param instruction
 */
extern unsigned char instruction_code(char *instruction);

/**
 * @brief print the op table
 *
 * @param op_tab
 */
extern void print_op_tab(const op_t *op_tab);

/**
 * @brief get the byte into a structure and write into the .cor file
 *
 * @param filename
 * @param file
 */
extern void get_byte_and_write(char *filename, file_t *file);
#endif /* !asm_h_ */
