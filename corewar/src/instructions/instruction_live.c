/*
** EPITECH PROJECT, 2023
** instructions
** File description:
** instruction_live
*/
#include "core.h"

void instruction_live(unsigned char *mem, cursor_node_t *cursor,
    process_t *proc)
{
    unsigned int player_id = 0;

    for (int i = 1; i < 5; i++) {
        player_id = (player_id << 8) | mem[cursor->position + i];
    }
    my_printf("live player_id = %d\n", player_id);
}