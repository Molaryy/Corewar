/*
** EPITECH PROJECT, 2023
** lib
** File description:
** my_strchr
*/

#include "jb.h"

extern char* my_strchr(const char* __first_str, char index)
{
    while (*(__first_str) != '\0') {
        if (*(__first_str) == index)
            return ((char*)__first_str);
        __first_str++;
    }
    if (*(__first_str) == index) {
        return ((char*)__first_str);
    }
    return NULL;
}

char* remove_char(const char* str, char c)
{
    const char* found = my_strchr(str, c);

    if (str == NULL || str[0] == '\0')
        return NULL;
    if (found != NULL) {
        size_t index = found - str;
        char* result = malloc(my_strlen(str) + 1);
        q_strcpy(result, str);
        my_memmove(result + index, result + index + 1,
                        my_strlen(result) - index);
        return result;
    }
    return (char*)str;
}

void my_memmove(void* destination, const void* source, size_t num_bytes)
{
    char* dest_ptr = (char*)destination;
    const char* src_ptr = (const char*)source;

    if (src_ptr < dest_ptr && dest_ptr < src_ptr + num_bytes) {
        for (size_t i = num_bytes; i > 0; --i) {
            *(dest_ptr + i - 1) = *(src_ptr + i - 1);
        }
    } else {
        for (size_t i = 0; i < num_bytes; ++i) {
            *(dest_ptr + i) = *(src_ptr + i);
        }
    }
}
