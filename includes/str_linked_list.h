/*
** EPITECH PROJECT, 2022
** str linked list struct
** File description:
** This is a str saved in a linked list used for my_printf
** because we need to prepend white spaces before the string
*/

#ifndef _MY_STR_LL
    #define _MY_STR_LL

    typedef struct str_ll_s {
        char c;
        struct str_ll_s *next;
    } str_ll_t;

#endif
