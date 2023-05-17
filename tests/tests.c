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
