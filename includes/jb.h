/*
** EPITECH PROJECT, 2023
** jb lib
** File description:
** jb
*/

#ifndef JB_H_
    #define JB_H_

    #include "stdio.h"
    #include <stdbool.h>
    #include <stddef.h>
    #include <unistd.h>
    #include <stdlib.h>

/**
 * @brief strcat
 *
 * @param dest
 * @param src
 * @return char*
 */
char *j_strcat(char const *dest, char const *src);

/**
 * @brief gets an array and transforms it into a string
 *
 * @param array char **
 * @param separator *char
 * @return char*
 */
char *array_to_str(char **array, char *separator);

/**
 * @brief check if a string contains a character
 *
 * @param str
 * @param to_find
 * @return true
 * @return false
 */
bool str_contains_char(char const *str, char to_find);

/**
 * @brief copy a string without a separator
 *
 * @param str
 * @param c
 * @return char*
 */
char *cpy_str_without_char(char *str, char c);

/**
 * @brief checks if a char is alphanumeric
 * @param c
 * @return
 */
bool is_char_alphanumeric(char c);

/**
 * @brief checks if a str is alphanumeric
 * @param str
 * @return
*/
bool is_str_alphanumeric(char *str);


/**
 * @brief frees an array content and te array itself
 *
 * @param array
 */
void free_array_str(char **array);

/**
 * @brief my_printf functions
 *
 * @param format
 * @param ...
 * @return int
 */
int my_printf(const char *format, ...);

/**
 * @brief prints only a char
 *
 * @param c
 * @return int
 */
int my_putchar(char c);

/**
 * @brief print tabs
 *
 * @param tab
 */
void print_tab(char **tab);

/**
 * @brief prints the number given in parameter
 *
 * @param nb
 * @return int
 */
int my_put_nbr(int nb);

/**
 * @brief prints a string
 *
 * @param str
 */
void my_putstr(char const *str);

int my_strlen(char const *str);

/**
 * @brief free array str
 *
1 * @param array
 */
void free_array_str(char **array);

/**
 * @brief converts an str to an array with char separatos
 *
 * @param str
 * @param separator
 * @return char**
 */
char **str_to_array_separator(char const *str, char *separator);

/**
 * @brief count the nb of cases that are not NULL in a 2D array
 *
 * @param tab
 * @return size_t
 */
size_t count_tab(char **tab);

/**
 * @brief compares a string
 * @param s1
 * @param s2
 * @return
 */
bool my_strcmp(char const *s1, char const *s2);

/**
 * @brief clean a string
 *
 * @param string
 * @return char*
 */
char *clean_string(char* string);

/**
 * @brief duplicate a string
 *
 * @param src
 * @return char*
 */
char *my_strdup(char const *src);

/*
 * @brief copys a string
 * @param src
 * @return
 */
char *my_strcpy(char *src);

/**
 * @brief gets the number in a string
 * @param str
 * @return
 */
int my_getnbr(char const *str);

/**
 * @brief check if digit or not
 *
 * @param c
 * @return true
 * @return false
 */
bool is_digit(char c);

/**
 * @brief prints
 *
 * @param nb
 * @param base
 */
void my_putnbr_base(int nb, char const *base);

/**
 * @brief copy of a char
 *
 * @param dest
 * @param src
 * @return char*
 */
extern char *q_strcpy(char *dest, char const *src);

/**
 * @brief cut a word when find the char index
 *
 * @param __first_str
 * @param index
 * @return char*
 */
extern char* my_strchr(const char* __first_str, char index);

/**
 * @brief strcat of quentin
 *
 * @param dest
 * @param src
 * @return char*
 */
char *q_strcat(char *dest, char const *src);

/**
 * @brief copies a tab to another
 *
 * @param tab
 * @return char**
 */
char **cpy_tab(char **tab, size_t start);

/**
 * @brief print a tab wit arrows
 *
 * @param tab
 */
void print_linked_tab(char **tab);

/**
 * @brief clean a str
 *
 * @param str
 * @param separators
 * @return char*
 */
char *clean_str(char const *str, char const *separators);

/**
 * @brief remove str beginnig
 *
 * @param str
 * @param separators
 * @return char*
 */
char *remove_str_beg_separator(char *str, char const *separators);

/**
 * @brief detects if a char is a separator
 *
 * @param c
 * @param separator
 * @return true
 * @return false
 */
bool is_separator(char c, char const *separator);

/**
 * @brief detect when there is a #
 *
 * @param str
 * @param separators
 * @return char*
 */
char *remove_after_separator(char *str, char const *separators);

/**
 * @brief memset of an str
 *
 * @param str
 * @return char*
 */
char *str_set(char *str);

/**
 * @brief check if a str is a number
 *
 * @param str
 * @return bool
 */
bool my_str_isnum(char const *str);

/*
 * @brief remove first char
 *
 * @param str
 * @param c
 * @return char*
 */
char* remove_char(const char* str, char c);
#endif /* JB_H_ */
