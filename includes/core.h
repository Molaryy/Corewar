/*
** EPITECH PROJECT, 2023
** include/core.h
** File description:
** vm for corewar header functions
*/

#ifndef CORE_H_
    #define CORE_H_
    #include "jb.h"

// %3 number 3
// 3 3 index from current
//

# define MEM_SIZE                (6*1024)
# define IDX_MOD                 512   /* modulo of the index < */
# define MAX_ARGS_NUMBER         4     /* this may not be changed 2^*IND_SIZE */

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

struct header_s
{
   int  magic;
# define COREWAR_EXEC_MAGIC      0xea83f3        /* why not */
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


typedef struct champion_t {
    int prog_nbr;
    int loaded_addr;
    char *filename;
} champion_t;

typedef struct vm_param_t {
    int nbr_cycle;
    champion_t *progs;
} vm_param_t;

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

#endif // CORE_H_
