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
    #include "cursors.h"

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
    # define T_IND           4       /* indirect always relative
                                    ( ld 1,r1 put what's in the address (1+pc)
                                    into r1 (4 bytes )) */

typedef struct op_s {
    char *mnemonique;
    char nbr_args;
    args_type_t type[MAX_ARGS_NUMBER];
    unsigned char code;
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
    int if_carry;
    int alive;
    int index_id;
} process_t;

typedef struct vm_t {
    unsigned char *memory;
    process_t *processes;
    int processes_size;
    int cycle_to_die;
} vm_t;

typedef struct stack_t {
    unsigned char *code;
    unsigned int code_size;
} stack_t;

typedef struct champion_t {
    int prog_nbr;
    int loaded_addr;
    char *filename;
    stack_t stack;
    char *name;
} champion_t;

typedef struct info_corewar_t {
    champion_t champions[100];
    cursor_t *cursors;
    int nb_champions;
    int dump;
    vm_t vm;
} info_corewar_t;

typedef struct instruction_s {
    void (*ptr)(unsigned char *mem, cursor_node_t *cursor, process_t *process);
} instruction_t;

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

/*
** @brief gets the address of the champion in the memory to be loaded
** @param num_champs int number of champions
** @param index int index of the champion
** @param length int length of the memory
** @returns int address of the champion
*/
int get_address(int num_champs, int index, int length);

/*
** @brief gets the number of .cor files in the arguments
** @param argc int number of arguments
** @param argv char** arguments
** @returns int number of champions
*/
int get_num_champs(int argc, char **argv);

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

/*==============================================================
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


/* ===========================================================================
** corewar/src/process/process.c
** ===========================================================================
*/

/*
** @brief this will initialize the memory of the vm and put the champions in
** with their processes
** @param info info_corewar_t * info struct of the corewar
** @return process_t ** array of process_t ** to be run with NULL being the
** memory that is unassigned
*/
void init_memory(info_corewar_t *info);

/*
** @brief this will initialize the processes of the champions given as args
** @param info info_corewar_t * info struct of the corewar
** @param processes process_t ** array of process_t ** to be edited
** @param champion champion_t champion to be added mainly having the code
** inside its stack_t struct
** @return void
*/
void init_processes(process_t **processes, champion_t champion);

/*
** @brief this will create a process_t struct with the given parameters inside
** the code inside the stack_t struct of the champion, it will parse the code
** and populate it with its operation.
** @param loaded_addr int where to load the champion in the memory
** @param index unsigned int *index of the code to be parsed
** @param code unsigned char * code to be parsed
** @return process_t * newly malloced process_t struct and populated properly
*/
process_t *init_process(int loaded_addr, unsigned int *index,
    unsigned char *code);

/* ===========================================================================
**                            END FILE
** ===========================================================================
*/


/* ===========================================================================
** corewar/src/process/helper.c
** ===========================================================================
*/

/*
** @brief this will create a template process_t struct with default values
** and a pc of the next process directly to the right modulo MEM_SIZE
** @param pc int program counter of the process so as said above the next
** process will be directly to the right of the current process modulo MEM_SIZE
** @return process_t * newly malloced process_t struct
*/
process_t process_create_null(int pc);

/* ===========================================================================
**                            END FILE
** ===========================================================================
*/


/* ===========================================================================
** corewar/src/process/init.c
** ===========================================================================
*/

/*
** @brief this will set a 32bit unsigned integer which uses an array of 4
** unsigned char which are 8 bits each for a total of 32 bits
** @param value int value to be set
** @param array unsigned char * array of 4 unsigned char to be set
** @return void
*/
void set_32uint(int value, unsigned char* array);

/*
** @brief this will get a 32bit unsigned integer which uses an array of 4
** unsigned char which are 8 bits each for a total of 32 bits
** @param array unsigned char * array of 4 unsigned char to be get
** @return unsigned int value of the 32bit unsigned integer
*/
unsigned int get_32uint(const unsigned char* array);

/* ===========================================================================
**                            END FILE
** ===========================================================================
*/


/* ===========================================================================
** corewar/src/process/init.c
** ===========================================================================
*/

/*
** @brief initialize the vm so memory and more
** @param info info_corewar_t * info struct of the corewar
** @return void
*/
void init_vm(info_corewar_t *info);

/* ===========================================================================
**                            END FILE
** ===========================================================================
*/


/* ===========================================================================
** corewar/src/process/init.c
** ===========================================================================
*/

/*
** @brief this will return the op_t struct of the given opcode
** @param opcode unsigned char opcode to be tested
** @return op_t * op_t struct of the given opcode
*/
op_t   get_op(unsigned char opcode);

/* ===========================================================================
**                            END FILE
** ===========================================================================
*/


/* ===========================================================================
** corewar/src/process/init.c
** ===========================================================================
*/

/*
** @brief this will return the prog_num of the champion depending on the
** position of the index inside the memory.
** @param info info_corewar_t * info struct of the corewar
** @param index int index of the memory
** @return int prog_num of the champion
*/
int get_champ_prog_nbr(info_corewar_t *info, int index);

/* ===========================================================================
**                            END FILE
** ===========================================================================
*/

/* ===========================================================================
** corewar/src/vm/run.c
** ===========================================================================
*/

/**
 * @brief Run the vm
 *
 * @param info info_corewar_t *
 */
void run_vm(info_corewar_t *info);

/* ===========================================================================
**                            END FILE
** ===========================================================================
*/

/* ===========================================================================
** corewar/src/instructions/do_instruction.c
** ===========================================================================
*/

/**
 * @brief Do the instruction of a cursor
 *
 * @param mem unsigned char *
 * @param cursor cursor_node_t *
 * @param proc process_t *
 */
void do_instruction(unsigned char *mem, cursor_node_t *cursor, process_t *proc);

/* ===========================================================================
**                            END FILE
** ===========================================================================
*/

/* ===========================================================================
** corewar/src/instructions/instruction_live.c
** ===========================================================================
*/

void instruction_live(unsigned char *mem, cursor_node_t *cursor,
    process_t *proc);

/* ===========================================================================
**                            END FILE
** ===========================================================================
*/

#endif // CORE_H_
