#include <stdio.h>

void Swap(int *a, int *b)
{
    int temp = 0;
    temp = *a;
    *a = *b;
    *b = temp;
}

void print_array(int a[], int num)
{
    int i = 0;
    for (i = 0; i < num; i++)
        printf("%d ", a[i]);
    printf("\n");
}
