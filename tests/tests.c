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

