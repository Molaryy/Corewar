/*
** EPITECH PROJECT, 2023
** include/core.h
** File description:
** vm for corewar header functions
*/

#ifndef CORE_H_
    #define CORE_H_

    #include <sys/stat.h>
    #include <stdlib.h>
    #include <fcntl.h>

    #include "jb.h"

// %3 number 3
// 3 3 index from current
//

# define MEM_SIZE                (6*1024)
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

struct  op_s
{
   char         *mnemonique;
   char         nbr_args;
   args_type_t  type[MAX_ARGS_NUMBER];
   char         code;
   int          nbr_cycles;
   char         *comment;
};

typedef struct op_s     op_t;

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

struct header_s
{
   int  magic;
   char prog_name[PROG_NAME_LENGTH + 1];
   int  prog_size;
   char comment[COMMENT_LENGTH + 1];
};

typedef struct header_s header_t;

/*
** live
*/
# define CYCLE_TO_DIE    1536    /* number of cycle before beig declared dead */
# define CYCLE_DELTA     5
# define NBR_LIVE        40

typedef struct process_t {
    register_t registers[REG_NUMBER];
    op_t operation;
} process_t;

typedef struct funct_t {
    process_t *processes;
} funct_t;

typedef struct stack_t {
    unsigned char current_index;
    int num_func;
    funct_t *functions;
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
    champion_t *champions;
    int nb_champions;
} info_corewar_t;

/* ===========================================================================
** corewar/src/helper/get.c
** ===========================================================================
*/

/*
** @brief gets the file size of the given filename
** @param filename char* filename or path
** @returns size of file given
*/
char *get_file_content(char *filename);

/*
** @brief gets the file size of the given filename
** @param filename char* filename or path
** @returns size of file given
*/
size_t get_file_size(char *filename);

/* ===========================================================================
**                            END FILE
** ===========================================================================
*/

/* ===========================================================================
** corewar/src/parser/parser.c
** ===========================================================================
*/

/*
** @brief this will creatd a champion_t structure that inside will call the
** stack_create function inside, a child structure of champion_t
** @param prog_nbr int the program or champion index to be referenced in
** output
** @param loaded_addr int where to load the champions code in the stack
** @param filename char* filename to find all the necessairy thing for
** the champion
** @returns champion_t
*/
champion_t champion_create(int prog_nbr, int loaded_addr, char *filename);

/*
** @brief this will create the stack of code to be run by the champion
** any unammed functions will be put into an anonymous function to be run
** sequentially
** @param filename char* filename of the parent function champion_create
** to populate attributes and code of the champion
** @returns stack_t
*/
stack_t stack_create(char *filename);

/* ===========================================================================
**                            END FILE
** ===========================================================================
*/

#endif // CORE_H_
