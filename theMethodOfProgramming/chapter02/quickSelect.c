#include <stdio.h>

/* solution_tc */
void swap(int * a, int * b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void QuickSelect(int a[], int k, int left, int right)
{
    int i, j;

    for (i = left; i <= right; right--)
        for (j = left; j <= right-1; j++)
            if (a[j] > a[j+1])
                swap(&a[j], &a[j+1]);

    for (i = 0; i < k; i++)
        printf("%d ", a[left+i]);
    printf("\n");
}

int main(int argc, char const *argv[])
{
    /* code */
    int array[] = {1,0,9,3,9,7,8,4,6,6,5,0,1,2,3,1,9,7,3,6,5};
    int k = 5;
    QuickSelect(array, 5, 0, sizeof(array)/sizeof(int) - 1);
    return 0;
}