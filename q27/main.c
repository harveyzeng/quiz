/* FIXME: Implement! */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static void swap_fun(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void shuffle(int arr[],int array_size)
{
    int j;
    srand((unsigned) time(NULL));
    for(int i = 0; i < array_size; i++) {
        j = i + rand() % (array_size - i);
        swap_fun(arr, i, j);
    }
}

void flawed_ASF_shuffling(int arr[],int array_size)
{
    int j;
    srand((unsigned) time(NULL));
    for(int i = 0; i < array_size; i++) {
        j = rand() % array_size ;
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
#if defined (SHF)
    shuffle(array,array_size);
#endif

#if defined (ASF)
    flawed_ASF_shuffling(array,array_size);
#endif
    for (int i = 0 ; i < array_size; i++) {
        printf("%d in %d\n", array[i], i);
    }
    return 0;
}
