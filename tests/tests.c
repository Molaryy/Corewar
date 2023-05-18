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

Test(print_bits, should_print_binary_representation)
{
    unsigned char byte = 0x0F;
    cr_redirect_stdout();  // Redirect stdout to capture the output
    print_bits(byte);
    cr_assert_stdout_eq_str("00001111\n");
}

// Test case for if_indirect_or_not function
/*Test(if_indirect_or_not, should_set_result_byte_correctly)
{
    const char *params[] = {"param1", "param2", "param3"};
    unsigned char result_byte = 0;
    int i = 0;
    if_indirect_or_not(params, &result_byte, i);
    unsigned char expected_result_byte = 
    cr_assert_eq(result_byte, expected_result_byte);
}

// Test case for create_byte function
Test(create_byte, should_create_correct_byte)
{
    char *param1 = "param1";
    char *param2 = "param2";
    char *param3 = "param3";
    unsigned char result = create_byte(param1, param2, param3);
    unsigned char expected_result = ;
    cr_assert_eq(result, expected_result);
}
*/
// Test case for coding_byte function
Test(coding_byte, should_print_byte_value)
{
    char *params[] = {"param1", "param2", "param3"};
    size_t nbParams = sizeof(params) / sizeof(params[0]);
    cr_redirect_stdout();  // Redirect stdout to capture the output
    coding_byte(params, nbParams);
    cr_assert_stdout_eq_str("Byte value: 0x12\n");
}