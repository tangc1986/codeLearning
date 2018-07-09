void InsertSort(int a[], int n)
{
    int i, j;
    for (i = 1; i < n; i++)
        for (j = i - 1; j >= 0 && a[j] > a[j + 1]; j--)
            Swap(&a[j], &a[j + 1]);
}
