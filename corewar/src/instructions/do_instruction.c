/*
** EPITECH PROJECT, 2023
** instructions
** File description:
** do_instruction
*/
#include "core.h"

static void move_cursor(unsigned char *mem, cursor_node_t *cursor)
{
    while (cursor->position < MEM_SIZE && !get_op(mem[cursor->position]).mnemonique)
        cursor->position++;
}

static int get_index(long long position, process_t *proc)
{
    int i = 0;

    for (; i < MEM_SIZE; i++) {
        if (proc[i].index_id == position)
            return (i);
    }
    return (-1);
}

void do_instruction(unsigned char *mem, cursor_node_t *cursor, process_t *proc)
{
    op_t op;

    if (cursor->nb_cycle != 0) {
        cursor->nb_cycle--;
        return;
    }
    op = get_op(mem[cursor->position]);
    if (op.code == 0) {
        move_cursor(mem, cursor);
        return;
    }
    
}
