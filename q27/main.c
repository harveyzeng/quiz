/* FIXME: Implement! */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap_fun(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void shuffle(int arr[],int array_size)
{
    srand((unsigned) time(NULL));
    for(int i = 0; i < array_size; i++) {
        int j = i + rand() % (array_size - i);
        swap_fun(arr, i, j);
    }
}

int main()
{
    int array_size = 52;
    int array[array_size];
    for (int i = 0 ; i < array_size; i++) {
        array[i] = i + 1;
    }
    shuffle(array,array_size);
    for (int i = 0 ; i < array_size; i++) {
        printf("%d in %d\n", array[i], i);
    }
    return 0;
}
