/*
** EPITECH PROJECT, 2023
** corewar/src/op.c
** File description:
** op.c file given by epitech to define all the functions in assembly
*/

#include "core.h"

const assembly_func_t  assembly_tab[] =
{
    {1, &my_live},
     {2, &do_load},
    // {3, &st},
    // {4, &add},
    // {5, &sub},
    // {6, &and},
    // {7, &or},
    // {8, &xor},
    // {9, &zjmp},
    // {10, &ldi},
    {11, &my_sti},
    // {12, &my_fork},
    // {13, &lld},
    // {14, &lldi},
    // {15, &lfork},
    {16, &my_aff},
    {0, &my_null}
};

void run_op(champion_t *champion, cursor_t *cursor, vm_t *vm)
{
    unsigned char code = vm->memory[get_32uint(cursor->pc.bytes)];

    for (size_t i = 0; i < sizeof(assembly_tab) / sizeof(assembly_func_t);
        i++) {
        if (assembly_tab[i].code == code) {
            assembly_tab[i].func(champion, cursor, vm, get_op(code));
            return;
        }
    }
    cursor_pop(cursor, &champion->cursor_head, &champion->cursor_tail);
}
