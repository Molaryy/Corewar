/*
** EPITECH PROJECT, 2022
** TESTS miniprintf
** File description:
** Unit tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "jb.h"
#include "asm.h"
#include "parser.h"

void my_redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(test_extension_1, test_extension_nb_1) {
    char const *filepath = "file.txt";
    bool result = detect_file_extension(filepath);
    cr_assert_eq(false, result);
}

Test(test_extension_2, test_extension_nb_1) {
    char const *filepath = "file.s";
    bool result = detect_file_extension(filepath);
    cr_assert_eq(true, result);
}

Test(print_bits, should_print_binary_representation, .init = my_redirect_all_std)
{
    unsigned char byte = 0x78;
    print_bits(byte);
    cr_assert_stdout_eq_str("Byte bits: 01 11 10 00\n");
}

Test(in_another_file, basic_test)
{
    char filepath[100] = "champion/Jon_Snow.s";
    in_another_file("Jon_Snow.s", filepath);
    cr_assert_str_eq(filepath, "Jon_Snow.s", "Error: Expected filepath to be 'Jon_Snow.s'");
}

Test(in_another_file, no_filename)
{
    char filepath[100] = "Jon_Snow.s";
    in_another_file(NULL, filepath);
    cr_assert_str_eq(filepath, "Jon_Snow.s", "Error: Expected filepath to be 'Jon_Snow.s'");
}

// Test de la fonction create_cor_file
Test(create_cor_file, basic_test)
{
    const char* str = "champion/Jon_Snow.s";
    char* filepath = create_cor_file(str);
    cr_assert_str_eq(filepath, "Jon_Snow.cor", "Error: Expected filepath to be 'Jon_Snow.cor'");
    free(filepath);
}

