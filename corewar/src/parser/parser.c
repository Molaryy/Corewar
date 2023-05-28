/*
** EPITECH PROJECT, 2023
** corewar/corewar/src/parser/parser.c
** File description:
** parser function for the executable of the vm for corewar
*/

#include "core.h"
#include "nc.h"

static int parse_args_loop(info_corewar_t *info, int argc, char **argv, int *i)
{
    int prog_num = info->nbr_champions + 1;
    int load_address = get_address(get_num_champs(argc, argv), prog_num,
        MEM_SIZE);

    for (; *i < argc; (*i)++) {
        if (my_strcmp("-n", argv[*i]) == 0)
            prog_num = my_getnbr(argv[++(*i)]);
        if (my_strcmp("-a", argv[*i]) == 0)
            load_address = my_getnbr(argv[++(*i)]);
        if (is_file(argv[*i]) == TRUE) {
            info->champions[++(info->nbr_champions)] = champion_create(prog_num,
                load_address, argv[(*i)++]);
            return TRUE;
        }
        if (my_strcmp("-n", argv[*i]) == 0 || my_strcmp("-a", argv[*i]) == 0)
            continue;
        return FALSE;
    }
    return FALSE;
}

static int parse_args_dump(info_corewar_t *info, char **argv, int *i)
{
    if (my_strcmp("-dump", argv[*i]) == 0) {
        if (my_str_isnum(argv[++(*i)]) == 0)
            return FALSE;
        info->dump = my_getnbr(argv[++(*i)]);
        return TRUE;
    }
    return TRUE;
}

info_corewar_t parse_args(int argc, char **argv)
{
    info_corewar_t info;
    int i = 1;

    if (argc < 2)
        exit(84);
    info.nbr_champions = -1;
    info.dump = -1;
    if (parse_args_dump(&info, argv, &i) == FALSE)
        exit(84);
    while (i < argc) {
        if (parse_args_loop(&info, argc, argv, &i) == FALSE ||
            my_strcmp(info.champions[info.nbr_champions].name, "ERROR") == 0) {
            my_printf("Invalid file\n");
            stop(&info, 84);
        }
    }
    return info;
}
