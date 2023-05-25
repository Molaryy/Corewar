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
    #include <endian.h>

    #define _BSD_SOURCE
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

    /*
    ** size (in bytes)
    */
    #define IND_SIZE        2
    #define DIR_SIZE        4
    #define REG_SIZE        DIR_SIZE
    #define LAB_SIZE        8

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
        int  prog_size;
        char description[COMMENT_LENGTH + 1];

    } header_t;

    typedef struct body_s {

        char **bodyArray;
        link_t *labels;

    } body_t;

    typedef struct champ_s {

        char *paramName;
        size_t nbParams;
        size_t index;
        char *label;
        char **params;
        bool isIndex[3];

    } champ_t;

    typedef struct instruc_byte_s {

        unsigned char* byte;

    } instruc_byte_t;

    typedef struct ParamByte_s {

        unsigned char* bytes;
        size_t size;

    } parambyte_t;

    typedef struct label_find_s {

        int adresse;
        char *name;

    } label_find_t;

    typedef struct file_s {

        char **origin_file;
        char **parsing_file;
        header_t *header;
        body_t *body;
        champ_t *champ;
        size_t nbLinesBody;
        instruc_byte_t *ins_bytes;
        char combinedDataHeader[PROG_NAME_LENGTH + COMMENT_LENGTH];
        int fd;
        size_t nbLabels;
        int offset;
        label_find_t *label_find;

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
bool check_type_arguments(char **line, parser_t *pars, size_t start,
                                size_t minus);

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
bool add_labels_to_link(body_t *body, file_t *file);

/**
 * @brief function to code in byte the parameter
 *
 * @param params
 * @param nbParams
 */
unsigned char coding_byte(char **params, size_t nbParams, file_t *file);

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
extern unsigned char instruction_code(char *instruction, file_t *file);

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

/**
 * @brief write the header
 * @param filename;
 * @param file
 */
extern void write_header(file_t *file, char *filename);

/**
 * @brief Get the register bytes object
 *
 * @param value
 * @param paramByte
 * @return unsigned*
 */
unsigned char* get_register_bytes(unsigned int value, parambyte_t *paramByte);

/**
 * @brief Get the direct bytes object
 *
 * @param value
 * @param paramByte
 * @return unsigned*
 */
unsigned char* get_direct_bytes(unsigned int value, parambyte_t *paramByte);

/**
 * @brief Get the indirect bytes object
 *
 * @param value
 * @param paramByte
 * @return unsigned*
 */
unsigned char* get_indirect_bytes(unsigned int value, parambyte_t *paramByte);

/**
 * @brief Get the value object
 *
 * @param param
 * @param opt
 * @return unsigned int
 */
unsigned int get_value(const char* param, int opt);

/**
 * @brief Create a param byte object
 *
 * @param param
 * @return parambyte_t*
 */
parambyte_t *create_param_byte(const char* param, file_t *file);

/**
 * @brief Create a zjmp bytes object
 *
 * @param param
 * @return parambyte_t*
 */
parambyte_t *create_zjmp_bytes(const char* param, file_t *file);

/**
 * @brief Create a ldi bytes object
 *
 * @param param
 * @param i
 * @return parambyte_t*
 */
parambyte_t *create_ldi_bytes(const char *param, file_t *file);

/**
 * @brief Create a sti bytes object
 *
 * @param param
 * @param i
 * @return parambyte_t*
 */
parambyte_t *create_sti_bytes(const char *param, file_t *file);

/**
 * @brief Create a fork bytes object
 *
 * @param param
 * @return parambyte_t*
 */
parambyte_t *create_fork_bytes(const char *param, file_t *file);

/**
 * @brief function to get the byte of parameter
 *
 * @param instruction
 * @param params
 */
void parameters_in_byte(file_t *file, char *instruction, char **params,
                        size_t nbParams);


/**
 * @brief Get the instruction index object
 *
 * @param flags
 * @param paramBytes
 * @param param
 * @param file
 * @return int
 */
int get_instruction_index(unsigned int flags, parambyte_t *paramBytes[],
                            char **param, file_t *file);

/**
 * @brief find param that have index
 *
 * @param instruction
 * @return unsigned int
 */
unsigned int find_index(char *instruction);

/**
 * @brief print byte to file
 *
 * @param paramByte
 * @param fd
 */
void print_bytes_to_file(const parambyte_t* paramByte, int fd);


/**
 * @brief debug for the champion structure
 *
 * @param champ
 */
void print_champion(champ_t *champ, size_t len);

/**
 * @brief Get the type object
 *
 * @param c
 * @param name
 * @param pos
 * @return size_t
 */
size_t get_type(char c, char *name, size_t pos);

/**
 * @brief init the champion structure
 *
 * @param champ
 * @param len
 * @return champ_t*
 */
champ_t *init_champ(champ_t *champ, size_t len);

/**
 * @brief Construct a new check index object
 *
 * @param champ
 * @param len
 */
void check_index(champ_t *champ, size_t len);

/**
 * @brief Get the Index object
 *
 * @param c
 * @return true
 * @return false
 */
bool get_index(char c);

/**
 * @brief check start
 *
 * @param c
 * @param start
 * @return size_t
 */
size_t check_start(char c, size_t start);

/*
 * @brief Get the tab objectget
 *
 * @param pars
 * @param start
 * @return char**
 */
char **get_tab(char **pars, size_t start);

/**
 * @brief get the label
 * 
 * @param file 
 */
extern void label_find(file_t *file);

/**
 * @brief starting to count
 * 
 * @param file 
 * @param i 
 * @return true 
 * @return false 
 */
bool starting_prog_size(file_t *file, int i);

/**
 * @brief handle the label for 1 param
 *
 * @param param
 * @param file
 * @param value
 * @return unsigned int
 */
unsigned int one_label_handling(const char *param, file_t *file,
                                unsigned int value);
#endif /* !asm_h_ */
