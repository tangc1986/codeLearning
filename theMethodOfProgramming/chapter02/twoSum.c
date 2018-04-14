#include <stdio.h>

/* solution_tc
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
*/

/* solution_01 */
void TwoSum(int data[], unsigned int length, int sum)
{
    //sort(s, s+n);   如果数组非有序的，那就事先排好序O(N log N)
    int begin = 0;
    int end = length - 1;

    //俩头夹逼，或称两个指针两端扫描法，很经典的方法，O(N)
    while (begin < end)
    {
        long currSum = data[begin] + data[end];
        if (currSum == sum)
        {
            //题目只要求输出满足条件的任意一对即可
            printf("%d %d\n", data[begin], data[end]);
            //如果需要所有满足条件的数组对，则需要加上下面两条语句：
            //begin++
            //end--
            break;
        }
        else
        {
            if (currSum < sum)
                begin++;
            else
                end--;
        }
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    int test[] = {1, 2, 4, 7, 11, 15};
    TwoSum(test, sizeof(test) / sizeof(int), 15);
    return 0;
}