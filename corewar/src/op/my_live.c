/*
** EPITECH PROJECT, 2023
** corewar/src/op/my_live.c
** File description:
** live function for the game
*/

#include "core.h"

void run_my_live(champion_t *champion, cursor_t *cursor, vm_t *vm,
    const op_t *op)
{
    my_printf("The player %d(%s)is alive.\n", champion->prog_nbr,
        champion->name);
    champion->last_live_cycle = vm->current_cycle;
    vm->nbr_live++;
    cursor->cycles_to_wait = op->nbr_cycles;
    cursor->carry = TRUE;
}

void my_live(champion_t *champion, cursor_t *cursor, vm_t *vm,
    const op_t *op)
{
    int index = (int) get_32uint(cursor->pc.bytes);
    int arg_size;

    for (int i = 0; i < op->nbr_args; i++) {
        arg_size = get_param(op->type[i], vm, index);
        if (arg_size == -1) {
            cursor_pop_cascade(cursor, &champion->cursor_head);
            return;
        }
        index += arg_size;
        if ((int) vm->memory[index % MEM_SIZE] == champion->prog_nbr) {
            run_my_live(champion, cursor, vm, op);
        }
    }
    set_32uint(++index % MEM_SIZE, cursor->pc.bytes);
}
