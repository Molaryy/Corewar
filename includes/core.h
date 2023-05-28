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

    #define UNUSED __attribute__((unused))

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
    # define REG_SIZE        1


    #define PARAM_TYPE_MASK_1 0xC0  // Bits 7 and 6
    #define PARAM_TYPE_MASK_2 0x30  // Bits 5 and 4
    #define PARAM_TYPE_MASK_3 0x0C  // Bits 3 and 2
    #define PARAM_TYPE_MASK_4 0x03  // Bits 1 and 0


/*
** op_tab
*/
extern  const op_t op_tab[];

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

    #define BOOL int

typedef struct file_t {
    char *file_content;
    size_t file_size;
} file_t;

typedef struct uint32_t {
    unsigned char bytes[4];
} uint32_t;

typedef struct vm_t {
    unsigned char *memory;
    int current_cycle;
    int cycle_to_die;
    int total_cycles;
    int nbr_live;
} vm_t;

typedef struct stack_t {
    unsigned char *code;
    unsigned int code_size;
} stack_t;

typedef struct cursor_t {
    uint32_t pc;
    BOOL carry;
    int cycles_to_wait;
    struct cursor_t *next;
    struct cursor_t *prev;
} cursor_t;

typedef struct champion_t {
    int prog_nbr;
    int loaded_addr;
    stack_t stack;
    char *name;
    int last_live_cycle;
    uint32_t registers[REG_NUMBER];
    cursor_t *cursor_head;
    cursor_t *cursor_tail;
} champion_t;

typedef struct info_corewar_t {
    champion_t champions[100];
    int nbr_champions;
    int dump;
    vm_t vm;
} info_corewar_t;

typedef struct assembly_func_t {
    unsigned char code;
    void (*func)(champion_t *champion, cursor_t *cursor, vm_t *vm,
        const op_t *op);
} assembly_func_t;

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
champion_t champion_create(info_corewar_t *info ,int prog_nbr, int loaded_addr,
    char *filename);

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
** corewar/src/vm/init.c
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
** corewar/src/datastructure/int32.c
** ===========================================================================
*/

/*
** @brief this will set a 32bit unsigned integer which uses an array of 4
** unsigned char which are 8 bits each for a total of 32 bits
** @param value int value to be set
** @param array unsigned char * array of 4 unsigned char to be set
** @return void
*/
void set_32uint(long long int value, unsigned char *array);

/*
** @brief this will get a 32bit unsigned integer which uses an array of 4
** unsigned char which are 8 bits each for a total of 32 bits
** @param array unsigned char * array of 4 unsigned char to be get
** @return unsigned int value of the 32bit unsigned integer
*/
long long int get_32uint(const unsigned char *array);

void disp_32uint_b(const unsigned char *array);

void disp_32uint_h(const unsigned char *array);

/* ===========================================================================
**                            END FILE
** ===========================================================================
*/


/* ===========================================================================
** corewar/src/op/run.c
** ===========================================================================
*/

/*
** @brief this is the main function that will run the operations and will call
** the necessary functions depending on the code in memory got thanks to vm
** @param cursor cursor_t * cursor of the process
** @param vm vm_t * vm of the corewar with the memory of the game, cycles and
** the live counters
** @return void
*/
void run_op(champion_t *champion, cursor_t *cursor, vm_t *vm);

/* ===========================================================================
**                            END FILE
** ===========================================================================
*/


/* ===========================================================================
** corewar/src/champion/get.c
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
** corewar/src/vm/helper.c
** ===========================================================================
*/

/*
** @brief this will check if the game has the win condition so if a champion
** runs the live operation between the life cycle of the game of which
** decreases by 5 for every life cycle, each champion must run this operation
** 40 times between each life cycle.
** @param info info_corewar_t * info struct of the corewar
** @return TRUE macro if found winner or no winner and FALSE macro if players
** live and so the game continues.
*/
int check_game_over(info_corewar_t *info);

/* ===========================================================================
**                            END FILE
** ===========================================================================
*/


/* ===========================================================================
** corewar/src/cursor/init.c
** ===========================================================================
*/

/*
** @brief this will initialize a cursor used for the first iteration of and
** creation of the champion.
** @param info info_corewar_t * info struct of the corewar so can free and stop
** the program if malloc fails
** @param index int index of the memory so here the load_addr of the champion
** @return cursor_t * cursor struct of the cursor
*/
cursor_t *cursor_init(info_corewar_t *info, int index);

/* ===========================================================================
**                            END FILE
** ===========================================================================
*/


/* ===========================================================================
** corewar/src/cursor/man.c
** ===========================================================================
*/

/*
** @brief this will create a cursor and add it to the cursor list at the head
** @param head cursor_t ** head of the cursor list
** @param index int index of the memory so here the load_addr of the champion
** @return void
*/
void cursor_push_head(cursor_t **head, int index);

/*
** @brief this remove cursor from the cursor list and update head and tail
** accordingly
** @param current cursor_t * current cursor to be removed
** @param head cursor_t ** head of the cursor list
** @param tail cursor_t ** tail of the cursor list
** @return void
*/
void cursor_pop(cursor_t *current, cursor_t **head, cursor_t **tail);

/*
** @brief this will pop the cursor from the cursor list and free it and it will
** cascade from head to the current cursor because when fork we add the cursor
** to the head and the last fork will be at tail so when a parent from the fork
** dies all its children must die too.
** @param current cursor_t * current cursor limit from head to this
** @param head cursor_t ** head of the cursor list
** @return void
*/
void cursor_pop_cascade(cursor_t *current, cursor_t **head);

/* ===========================================================================
**                            END FILE
** ===========================================================================
*/


/* ===========================================================================
** corewar/src/champion/run.c
** ===========================================================================
*/

/*
** @brief this will loop over all the champions and run each cursor of each
** champion
** @param champions champion_t * array of champion_t struct
** @param num_champs int number of champions
** @param vm vm_t * vm struct of the vm with memory and cycles and lives
** @return void
*/
void run_champions(champion_t *champions, int num_champs, vm_t *vm);

/*
** @brief this will loop over all the cursors of the champion and run each
** of them waiting for the cycles if needed and updating them if needed.
** @param champion champion_t * champion struct passed my reference.
** @param vm vm_t * vm struct of the vm with memory and cycles and lives
** @return void
*/
void run_champion(champion_t *champion, vm_t *vm);

/* ===========================================================================
**                            END FILE
** ===========================================================================
*/


/* ===========================================================================
** corewar/src/op/get.c
** ===========================================================================
*/

/*
** @brief this will get the size of of the param depending on the type of the
** param by checking if the byte is 0 because realistically the param only
** takes 1 byte and if the byte is 0 it means that the param is encoded on
** the next byte. If sabotaged by another champion and the byte is corrupted
** it will return -1 and so the operation will not run outside the this
** function.
** @param args_type args_type_t the given arg with bitwise or of the types
** accepted by the process.
** @param vm vm_t * vm struct of the vm with memory, cycles and lives
** @param index int index of the memory
*/
int get_param(args_type_t args_type, vm_t *vm, int index);

/*
** @brief this will return the op_t struct of the given opcode
** @param opcode unsigned char opcode to be tested
** @return op_t * op_t struct of the given opcode
*/
const op_t *get_op(unsigned char opcode);

/* ===========================================================================
**                            END FILE
** ===========================================================================
*/


/* ===========================================================================
** corewar/src/op/my_live.c
** ===========================================================================
*/

/*
** @brief this will run the live operation and will update the live counter
** of the champion and the live counter of the vm if error in code and cannot
** run the operation it will pop the cursor cascading if needed (if child of
** fork) and will update the cursor->pc to the next operation.
** @param champion champion_t * champion struct passed my reference.
** @param cursor cursor_t * cursor struct passed my reference.
** @param vm vm_t * vm struct of the vm with memory and cycles and lives
** @param args args_type_t args[MAX_ARGS_NUMBER] array of args type
** @return void
*/
void my_live(champion_t *champion, cursor_t *cursor, vm_t *vm,
    const op_t *op);

/* ===========================================================================
**                            END FILE
** ===========================================================================
*/


/* ===========================================================================
** corewar/src/op/my_live.c
** ===========================================================================
*/

/*
** @brief this is the null function for unmapped memory and will update the
** cursor->pc to the next operation.
** @param champion champion_t * champion struct passed my reference.
** @param cursor cursor_t * cursor struct passed my reference.
** @param vm vm_t * vm struct of the vm with memory and cycles and lives
** @param args args_type_t args[MAX_ARGS_NUMBER] array of args type
** @return void
*/
void my_null(champion_t *champion, cursor_t *cursor, vm_t *vm, const op_t *op);

void my_aff(champion_t *champion, cursor_t *cursor, vm_t *vm, const op_t *op);

void my_sti(champion_t *champion, cursor_t *cursor, vm_t *vm, const op_t *op);

/* ===========================================================================
**                            END FILE
** ===========================================================================
*/

/* ===========================================================================
** corewar/src/op/do_load.c
** ===========================================================================
*/

/**
 * @brief do load instruction
 *
 * @param champion champion_t *
 * @param cursor cursor_t *
 * @param vm vm_t *vm
 * @param op op_t *
 */
void do_load(champion_t *champion, cursor_t *cursor, vm_t *vm,
    const op_t *op);

/* ===========================================================================
**                            END FILE
** ===========================================================================
*/

/* ===========================================================================
** corewar/src/op/int_to_bytes.c
** ===========================================================================
*/

/**
 * @brief put value into a unsigned char[4]
 *
 * @param value int
 * @param buffer unsigned char[4]
 */
void int_to_bytes(int value, unsigned char buffer[4]);

/* ===========================================================================
**                            END FILE
** ===========================================================================
*/

/* ===========================================================================
** corewar/src/op/do_load.c
** ===========================================================================
*/

/**
 * @brief do zjmp instruction
 *
 * @param champion champion_t *
 * @param cursor cursor_t *
 * @param vm vm_t *vm
 * @param op op_t *
 */
void do_zjmp(champion_t *champion, cursor_t *cursor, vm_t *vm,
    const op_t *op);

/* ===========================================================================
**                            END FILE
** ===========================================================================
*/


#endif // CORE_H_
