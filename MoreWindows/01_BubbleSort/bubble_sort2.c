#include <stdbool.h>

void BubbleSort(int a[], int n)  
{  
    int j, k;  
    bool flag;  
  
    k = n;  
    flag = true;  
    while (flag)  
    {  
        flag = false;  
        for (j = 1; j < k; j++)  
            if (a[j - 1] > a[j])  
            {  
                Swap(&a[j - 1], &a[j]);  
                flag = true;  
            }  
            k--;  
    }
}  
