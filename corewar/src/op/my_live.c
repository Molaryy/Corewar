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
    long long int arg;
    uint32_t tmp = {0};

    for (int i = 0; i < REG_SIZE; i++)
        tmp.bytes[i] = vm->memory[(index + i + 1) % MEM_SIZE];
    for (int i = 0; i < op->nbr_args; i++) {
        index += REG_SIZE;
        arg = get_32uint(tmp.bytes);
        if (arg == (long long int) champion->prog_nbr) {
            run_my_live(champion, cursor, vm, op);
        }
    }
    set_32uint(++index % MEM_SIZE, cursor->pc.bytes);
}
