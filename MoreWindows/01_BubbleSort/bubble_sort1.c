void BubbleSort(int a[], int n)
{
    int i, j;
    for (i = 0; i < n; i++)
        for (j = 1; j < n - i; j++)
            if (a[j - 1] > a[j])
                Swap(&a[j - 1], &a[j]);
}
