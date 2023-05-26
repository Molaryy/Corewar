/*
** EPITECH PROJECT, 2022
** task02 concat_params
** File description:
** concatenates the command-line arguments
*/

#include <stdlib.h>

int my_strlen(char const *str);

int get_total_len(int argc, char **argv)
{
    int i = 0;
    unsigned int tot_len = 0;

    while (i < argc) {
        tot_len += sizeof(char) * (my_strlen(argv[i]) + 1);
        i++;
    }
    return tot_len;
}

char *concat_params(int argc, char **argv)
{
    char *str;
    int count = 0;
    int tot_len = get_total_len(argc, argv);

    str = malloc(sizeof(char) * tot_len);
    for (int i = 0; i < argc; i++) {
        for (int j = 0; j < my_strlen(argv[i]); j++) {
            str[count] = argv[i][j];
            count++;
        }
        str[count] = '\n';
        count++;
    }

    str[count] = '\0';
    return str;
}
