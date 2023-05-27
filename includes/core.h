/*
** EPITECH PROJECT, 2023
** include/core.h
** File description:
** vm for corewar header functions
*/

#ifndef CORE_H_
    #define CORE_H_

    #include <stdlib.h>
    #include <fcntl.h>
    #include <unistd.h>

    #include "nc.h"

    #define TRUE 0
    #define FALSE -1

    #define READ_LEN 3

    // %3 number 3
    // 3 3 index from current
    //

    # define MEM_SIZE                (6 * 1024)
    # define IDX_MOD                 512
    # define MAX_ARGS_NUMBER         4

    # define COMMENT_CHAR            '#'
    # define LABEL_CHAR              ':'
    # define DIRECT_CHAR             '%'
    # define SEPARATOR_CHAR          ','

    # define LABEL_CHARS             "abcdefghijklmnopqrstuvwxyz_0123456789"

    # define NAME_CMD_STRING         ".name"
    # define COMMENT_CMD_STRING      ".comment"

    /*
    ** regs
    */

    # define REG_NUMBER      16              /* r1 <--> rx */

    /*
    **
    */

    typedef char    args_type_t;

    # define T_REG           1       /* register */
    # define T_DIR           2       /* direct  (ld  #1,r1  put 1 into r1) */
    # define T_BOTH          3       /* bot deirect or register */
    # define T_IND           4       /* indirect always relative
                                    ( ld 1,r1 put what's in the address (1+pc)
                                    into r1 (4 bytes )) */

typedef struct op_s {
    char *mnemonique;
    char nbr_args;
    args_type_t type[MAX_ARGS_NUMBER];
    char code;
    int nbr_cycles;
    char *comment;
} op_t;

    /*
    ** size (in bytes)
    */
    # define IND_SIZE        2
    # define DIR_SIZE        4
    # define REG_SIZE        DIR_SIZE

/*
** op_tab
*/
extern  op_t    op_tab[];

    /*
    ** header
    */
    # define PROG_NAME_LENGTH        128
    # define COMMENT_LENGTH          2048
    # define COREWAR_EXEC_MAGIC      0xea83f3

struct header_s {
    int  magic;
    char prog_name[PROG_NAME_LENGTH + 1];
    int  prog_size;
    char comment[COMMENT_LENGTH + 1];
};

typedef struct header_s header_t;

    /*
    ** live
    */
    # define CYCLE_TO_DIE    1536
    # define CYCLE_DELTA     5
    # define NBR_LIVE        40

typedef struct file_t {
    char *file_content;
    size_t file_size;
} file_t;

typedef struct uint32_t {
    unsigned char byte[4];
} uint32_t;

typedef struct process_t {
    uint32_t registers[REG_NUMBER];
    op_t operation;
    int pc;
    int carry;
    int cycle;
    int alive;
} process_t;

typedef struct funct_t {
    process_t *processes;
} funct_t;

typedef struct stack_t {
    unsigned char current_index;
    char *code;
    unsigned code_size;
} stack_t;

typedef struct champion_t {
    int prog_nbr;
    int loaded_addr;
    char *filename;
    stack_t stack;
    char *name;
} champion_t;

typedef struct vm_param_t {
    int nbr_cycle;
    champion_t *progs;
} vm_param_t;

typedef struct info_corewar_t {
    champion_t champions[100];
    int nb_champions;
    int dump;
} info_corewar_t;

/* ===========================================================================
** corewar/src/helper/get.c
** ===========================================================================
*/

/*
** @brief gets the file size of the given filename and gets the file contents
** of the given filename
** @param filename char* filename or path
** @returns file_t struct with file contents and file size
*/
file_t get_file_content(char *filename);

int get_address(int num_champs, int index, int length);

/* ===========================================================================
**                            END FILE
** ===========================================================================
*/


/* ===========================================================================
** corewar/src/helper/misc.c
** ===========================================================================
*/

/*
** @brief checks if a given filename is a file or not
** @param filename char* filename or path
** @returns boolean macro
*/
int is_file(const char *filename);

/* ===========================================================================
**                            END FILE
** ===========================================================================
*/


/* ===========================================================================
** corewar/src/champion/champion.c
** ===========================================================================
*/

/*
** @brief this will created a champion_t structure that inside will call the
** stack_create function inside, a child structure of champion_t
** @param prog_nbr int the program or champion index to be referenced in
** output
** @param loaded_addr int where to load the champions code in the stack
** @param filename char* filename to find all the necessary thing for
** the champion
** @returns champion_t
*/
champion_t champion_create(int prog_nbr, int loaded_addr, char *filename);

/* ===========================================================================
**                            END FILE
** ===========================================================================
*/


/* ===========================================================================
** corewar/src/champion/stack.c
** ===========================================================================
*/

/*
** @brief this will create the stack of code to be run by the champion
** any unnamed functions will be put into an anonymous function to be run
** sequentially
** @param filename char* filename of the parent function champion_create
** to populate attributes and code of the champion
** @returns stack_t
*/
stack_t stack_create(champion_t *champ, char *filename);

/* ===========================================================================
**                            END FILE
** ===========================================================================
*/

/* ===========================================================================
** corewar/src/parser/parser.c
** ===========================================================================
*/

/*
** @brief this will parse the args given and make the champions
** @param argc int number of args
** @param argv char** array of args
** @returns int either TRUE macro if successful or FALSE macro if not
*/
info_corewar_t parse_args(int argc, char **argv);

/* ===========================================================================
**                            END FILE
** ===========================================================================
*/


/* ===========================================================================
** corewar/src/helper/str.c
** ===========================================================================
*/

/*
** @brief this will check is a char is alpha numeric
** @param c char to be tested
** @return TRUE of FALSE macro
*/
int my_is_char_alphanumeric(char c);

/*
** @brief this will trim the string of unwanted chars
** @param str char * to be tested
** @param len int length of the given string since we can't test for \0
** @return char * newly malloced string that was trimmed
*/
char *trim_str(char *str, int len);

/* ===========================================================================
**                            END FILE
** ===========================================================================
*/


/* ===========================================================================
** corewar/src/helper/stop.c
** ===========================================================================
*/

/*
** @brief this will free all necessary resources and exit the program
** @param info info_corewar_t * info structure to be freed
** @param int value to be exited
** @return void
*/
void stop(info_corewar_t *info, int status);

/* ===========================================================================
**                            END FILE
** ===========================================================================
*/


/* ===========================================================================
** corewar/src/helper/debug.c
** ===========================================================================
*/

/*
** @brief this will display the debug information so the content of the
** champion_t structure
** @param champion champion_t * champion to be displayed
** @return void
*/
void display_champion(champion_t *champion);

/*
** @brief this will display the content of the info_corewar_t structure
** @param info info_corewar_t structure
** @return void
*/
void display_info(info_corewar_t *info);

/* ===========================================================================
**                            END FILE
** ===========================================================================
*/


/* ===========================================================================
** corewar/src/helper/free.c
** ===========================================================================
*/

/*
** @brief this will free 3 mallocs
** @param str1 char * first malloc to be freed
** @param str2 char * second malloc to be freed
** @param str3 char * third malloc to be freed
** @return void
*/
void free_3(char *str1, char *str2, char *str3);

/*
** @brief this will free 2 mallocs
** @param str1 char * first malloc to be freed
** @param str2 char * second malloc to be freed
** @return void
*/
void free_2(char *str1, char *str2);

/* ===========================================================================
**                            END FILE
** ===========================================================================
*/



#endif // CORE_H_
