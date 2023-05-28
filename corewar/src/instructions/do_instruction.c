/*
** EPITECH PROJECT, 2023
** instructions
** File description:
** do_instruction
*/
#include "core.h"

static void move_cursor(unsigned char *mem, cursor_node_t *cursor)
{
    unsigned int position = cursor->position;

    while (cursor->position < MEM_SIZE) {
        if (get_op(mem[cursor->position]).code != 0)
            return;
        cursor->position++;
    }
    cursor->position = 0;
    while (cursor->position != position) {
        if (get_op(mem[cursor->position]).code != 0)
            return;
        cursor->position++;
    }
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

static void handle_instruction(unsigned char *mem, cursor_node_t *cursor, process_t *proc, instruction_t instruction)
{
    if (cursor->check && cursor->nb_cycle == 0) {
        instruction.ptr(mem, cursor, proc);
        cursor->check = false;
    }
    return;
}

static void handle_check(cursor_node_t *cursor, unsigned int i)
{
    int nb_cycle[] = {10, 5, 5, 10, 10, 6, 6, 6, 20, 25, 25, 800, 10, 50, 1000, 2};

    if (cursor->check == false) {
        cursor->nb_cycle = nb_cycle[i];
        cursor->check = true;
    }
    return;
}

static void do_instruction_current(unsigned char *mem, cursor_node_t *cursor,
    process_t *proc)
{
    int flag[] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08,
        0x09, 0x0a, 0x0b, 0x0c, 0x0c, 0x0d, 0x0e, 0x00};
    unsigned int i = 0;
    instruction_t instruction[] = {instruction_live, NULL};

    while (flag[i] != 0x00) {
        //my_printf("flags[0] = %d\n", flag[0]);
        //my_printf("cursor_position = %d\n", cursor->position);
        //my_printf("mem[cursor_position] = %d\n", mem[cursor->position]);
        if (flag[i] == mem[cursor->position] && i == 0) { // retirer i == 1
            my_printf("here\n");
            handle_check(cursor, i);
            handle_instruction(mem, cursor, proc, instruction[i]);
            return;
        }
        i++;
    }
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
    do_instruction_current(mem, cursor, proc);
    if (cursor->nb_cycle == 0 && cursor->check == false)
        move_cursor(mem, cursor);
}
