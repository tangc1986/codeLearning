#include <stdio.h>

/* solution_tc */
void QuickSelect(int a[], int k, int left, int right)
{
    int i = 0, j =0;
    int *kList = (int*)malloc(k*sizeof(int));
    memset(kList, 0, k*sizeof(int));
    for (i = left; i <= right; i++)
    {
        if (i < left+k)
        {
            kList[i-left] = a[i];
            for(j=0;j<k;j++)
                printf("%d ", kList[j]);
            printf("\n");
        }
        else
        {
            for (j=0; j<k; j++)
            {
                if (a[i]<kList[j])
                {
                    kList[j]=a[i];
                    for(j=0;j<k;j++)
                        printf("%d ", kList[j]);
                    printf("\n");
                    break;
                }
            }
        }
    }

    for(j=0;j<k;j++)
        printf("%d ", kList[j]);
    printf("\n");
    
    free((void *)kList);
}

int main(int argc, char const *argv[])
{
    /* code */
    int array[] = {1,0,9,3,9,7,8,4,6,6,5,0,5,2,3,1,9,7,3,6,5};
    int k = 5;
    QuickSelect(array, 5, 0, sizeof(array)/sizeof(int) - 1);
    return 0;
}