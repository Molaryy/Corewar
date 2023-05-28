/*
** EPITECH PROJECT, 2023
** corewar/src/champion/run.c
** File description:
** deals with the running of champions in main game loop
*/

#include "core.h"

void run_champion(champion_t *champion, vm_t *vm)
{
    cursor_t *cursor = champion->cursor_tail;

    for (; cursor != NULL; cursor = cursor->prev) {
        if (cursor->cycles_to_wait == 0)
            run_op(cursor, vm);
        if (cursor->cycles_to_wait > 0)
            cursor->cycles_to_wait--;
    }
}

void run_champions(champion_t *champions, int num_champs, vm_t *vm)
{
    for (int i = 0; i <= num_champs ; i++) {
        run_champion(&champions[i], vm);
    }
}
