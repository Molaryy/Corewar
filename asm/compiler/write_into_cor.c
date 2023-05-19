/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** write_into_cor
*/

#include "asm.h"

static void write_bytes_to_file(const unsigned char *bytes, size_t size,
                const char *filename)
{
    int file = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (file == -1) {
        my_printf("Error when opening the file.\n");
        return;
    }
    ssize_t written = write(file, bytes, size);
    if (written == -1) {
        my_printf("Error when writing to the file.\n");
    } else if (written != size) {
        my_printf("Error: number of bytes written different from the size.\n");
    } else {
        my_printf("The bytes have been written to the file successfully\n.");
    }
    close(file);
}

extern void get_byte_and_write(char *filename, file_t *file)
{
    char *params[] = {"r1", "%:crow", "%1"};

    file->octet_bytes.bytes[0] = instruction_code("sti");
    file->octet_bytes.bytes[1] = coding_byte(params, 3);

    write_bytes_to_file(file->octet_bytes.bytes, MAX_BYTES, filename);
}
