/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** instruction_code
*/

#include "asm.h"

static int get_instruction_code(const char *instruction, op_t *op_tab)
{
    for (int i = 0; op_tab[i].mnemonique != NULL; i++) {
        if (my_strcmp(instruction, op_tab[i].mnemonique)) {
            return op_tab[i].code;
        }
    }
    return FAILURE;
}

extern unsigned char instruction_code(char *instruction, file_t *file)
{
    int code = get_instruction_code(instruction, op_tab);
    unsigned char instruction_byte;

    if (code == FAILURE) {
        my_printf("instruction not found !\n");
        exit(FAILURE);
    } else {
        instruction_byte = (unsigned char) code;
    }
    file->offset++;
    return instruction_byte;
}

extern void print_op_tab(const op_t *op_tab)
{
    for (int i = 0; op_tab[i].mnemonique != 0; i++) {
        my_printf("Op[%d]:\n", i);
        my_printf("mnemonique: %s\n", op_tab[i].mnemonique);
        my_printf("nbr_args: %d\n", op_tab[i].nbr_args);
        my_printf("type: ");
        for (int j = 0; j < op_tab[i].nbr_args; j++)
            my_printf("%d ", op_tab[i].type[j]);
        my_printf("\n");
        my_printf("code: %d\n", op_tab[i].code);
        my_printf("nbr_cycles: %d\n", op_tab[i].nbr_cycles);
        my_printf("comment: %s\n", op_tab[i].comment);
    }
}
