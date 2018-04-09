#include <stdio.h>

void TwoSum(int data[], unsigned int length, int sum)
{
    int i, j;
    for (i = 0; i < length; i++)
    {
        for (j = i+1; j < length; j++)
        {
            if ((data[i] + data[j]) == sum)
            {
                printf("%d %d\n", data[i], data[j]);
                return;
            }
        }
    }
    printf("Can not find!!!\n");
}

int main(int argc, char const *argv[])
{
    /* code */
    int test[] = {1, 2, 4, 6, 11, 17};
    TwoSum(test, sizeof(test)/sizeof(int), 27);
    return 0;
}