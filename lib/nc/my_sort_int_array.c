/*
** EPITECH PROJECT, 2022
** my_sort_int_array
** File description:
** This will sort an array of ints
*/

void swap(int *a, int *b)
{
    int temp = *a;

    *a = *b;
    *b = temp;
}

void bubble_sort2(int *array, int n, int i)
{
    for (int j = 0; j < n - i - 1; j++) {
        if (array[i] > array[ j + 1 ]) {
            swap(&array[j], &array[ j + 1 ]);
        }
    }
}

void my_sort_int_array(int *array, int size)
{
    for (int i = 0; i < size - 1; i++) {
        bubble_sort2(array, size, i);
    }
}
