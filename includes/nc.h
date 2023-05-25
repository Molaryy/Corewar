/*
** EPITECH PROJECT, 2022
** printf header
** File description:
** Nathan Coquelin's lib functions
*/

#ifndef _LIB_NC_
    #define _LIB_NC_

    #include <stddef.h>
    #include <stdarg.h>
    #include <stdlib.h>

    #include "str_linked_list.h"
    #include "flags.h"


    #define TRUE 0
    #define FALSE -1

void my_putchar(char c);
int my_isneg(int nb);
int my_put_nbr(int nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_putstr_printf_inte(char const *str, int *char_count);
int my_strlen(char const *str);
int my_getnbr(char const *str);
void my_sort_int_array(int *tab, int size);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int root(int guess, int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_showstr(char const *str);
int my_showmem(char const *str, int size);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
int my_isalpha(char c);
int find_prime_rec(int nb);
int test_is_low(char c);
void frec(int i);
int found_whole(int x, int n);
int prec(int test_value, int b);
int test_is_upper(char c);
int get_min_len(char const *a, char const *b);
void bubble_sort2(int *array, int n, int i);
int is_ascii(char c);
int is_root(int guess, int b);
int is_alpha(char c);
int test_is_char(char c);
int test_is_num(char c);
int evaluate_equal(char const *str, char const *to_find);
int compute_char(char c, int number);
void my_swap_char(char *a, char *b);
char *my_charupcase(char *str);
int evaluate_diff_char(char const a, char const b);
int evaluate_diff_char_placing(char const a, char const b);
int check_is_neg2(int n);
int power_is_satisfy2(int n);
int powrec(int last_n, int p, int is_neg);
int test_if_overflow2(int neg, int p, int last_res, int next_res);
int get_tot_num_of_words(const char *str);
int jump_all_non_alpha(char const *str, int d);
char **my_str_to_word_array(char const *str);
char *concat_params(int argc, char **argv);
int get_total_len(int argc, char **argv);
char *my_strdup(char const *src);
int my_show_word_array(char * const * tab);
void swap(int *a, int *b);
char *my_strlowcase(char *str);
int my_strlen(char const *str);
int my_putchar_printf(const char c, int *count);
int my_putstr_printf(va_list arguments, int *count, specifier_t specifier);
void frec_printf( int i, str_ll_t *buffer);
int my_put_nbr_printf(va_list arguments, int *char_count,
    specifier_t specifier);
void brec_printf(int i, char * base, int *count, int *error);
int my_getnbr_printf(char const *str, int i);
unsigned int my_log(unsigned int n, unsigned int base);
str_ll_t * my_ll_add(str_ll_t * current_node, char ch);
int my_list_size(str_ll_t *begin);
int my_put_ll(str_ll_t *head, int *char_count);
int is_in_delimeter(char search_for, char *search_in);
int get_tot_wanted_sec(const char *str, char *delimeter);
int jump_delimeters(char const *str, int d, char *delimeter);
char ** my_strtok(char const * str, char delimeter);
int is_in_delimeter_printf(char search_for, char *search_in);
int get_tot_wanted_sec_printf(const char *str, char *delimeter);
int jump_delimeters_printf(char const *str, int d, char *delimeter);
char ** my_strtok_printf(char const * str, int pos, char *delimeter);
str_ll_t add_padding_printf(str_ll_t *memory, int min_width);
int evaluate_flags(update_specifier_t *specifier_m, va_list arguments);
int evaluate_and_disp(update_specifier_t *specifier_m,  va_list arguments);
int my_printf(char *format, ...);
const flag_t *get_flag(char c);
void populate_ll_specifier(update_specifier_t *specifier_m);
str_ll_t *iterate_n(str_ll_t *str, int n);
specifier_t update_specifier(update_specifier_t *specifier_m,
    va_list arguments);
char get_last_ll(str_ll_t *str);
specifier_t parse_flags(update_specifier_t *specifier_m, va_list arguments);
void show_specifier(specifier_t specifier);
int my_put_float(va_list arguments, int *char_count, specifier_t specifier);
int my_put_nbr_printf2(int n, int *char_count);
int frec_printf2(int n, int *char_count);
unsigned int my_log(unsigned int n, unsigned int base);
int free_str_ll(str_ll_t *node);
str_ll_t *iterate_ll(str_ll_t *node, int i);
specifier_t error_struct(void);
void error_specifier_m(update_specifier_t *specifier_m);
void error_output(str_ll_t **specifier, int *char_count);
int is_valid_conversion_specifier(char c);
void update_specifier_flag(update_specifier_t *specifier_m);
void update_specifier_min_width(update_specifier_t *specifier_m,
    va_list arguments);
void update_specifier_precision(update_specifier_t *specifier_m,
    va_list arguments);
void update_specifier_length_modifier(update_specifier_t *specifier_m,
    va_list arguments);
int my_put_science(va_list arguments, int *char_count, specifier_t specifier);
void my_put_power(int i, int *char_count);
int nbr_puissance(float nb);
void add_padding_right(specifier_t specifier, int *count, char *str);
int flag_g(va_list arguments, int *count_char, specifier_t specifier);
int my_pointers_hexa(va_list arguments, int *count_char,
    specifier_t specifier);
int my_put_base_printf2(size_t n, char * base, int *count);
int my_convert_hexa(va_list arguments, int *char_count, specifier_t specifier);
int my_put_base_printf(long long int n, char * base, int *count);
int my_convert_octal(va_list arguments, int *char_count, specifier_t specifier);
int my_put_nbr_printf_unsigned(va_list arguments, int *char_count,
    specifier_t specifier);
specifier_t init_specifier_t(void);
void cut_fonction3(specifier_t specifier,
    int width, int padding_char, int *char_count);
int my_getnbr_index(char const *str, unsigned int index);
unsigned int my_getnbr_index_u(char const *str, unsigned int index);
char **my_strtok_s(char const *str, char delimeter, int index);
char *my_strdup_s(char const *src, int index);
char * my_strdup_f(char *src);
char *my_strcat_n(char const *dest, char const *src);
int my_strcmp_f(char const *s1, char const *s2, int index);
int check_in_delimeter(const char needle, const char *haystack);
int get_tot_wanted_sec_a(const char * str, char *delimeters);
int jump_delimeters_a(char const *str, int d, char *delimeters);
char **my_strtok_a(char const * str, char *delimeters);

/* ===========================================================================
** ../lib/my/realloc_char.c
** ==========================================================================
*/
int get_arrlen(char **arr);
int free_arr(char **arr);
char **realloc_char(char **arr, char *new);
char **cust_realloc_char(char **arr, char *new);

/* ===========================================================================
** ../lib/my/my_strtok_quotes.c
** ==========================================================================
*/
char **my_strtok_quotes(char *str, char *delimiter);

#endif
