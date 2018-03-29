#include <stdio.h>

/* solution_tc
void PrintPermutation(char * prefix, int prefixLen, char * perm, int permLen)
{
    int i = 0;
    char *str = malloc(prefixLen+1);
    memset(str, 0, prefixLen+1);
    memcpy(str, prefix, prefixLen);
    if (permLen == 1)
        printf("%s%c\n", str, perm[0]);
    else
    {
        for (i = 0; i < permLen; i++)
        {
            str[prefixLen] = perm[i];
            char *permStr = malloc(permLen-1);
            memset(permStr, 0, permLen-1);
            memcpy(permStr, perm, i);
            memcpy(permStr+i, perm+i+1, permLen-i-1);
            PrintPermutation(str, prefixLen+1, permStr, permLen-1);
            free(permStr);
        }
    }
    free(str);
}

void CalcAllPermutation(char * perm, int from, int to)
{
    PrintPermutation("", 0, perm, to-from+1);
}
 */

/* solution_01
void swap(char * a, char * b)
{
    if (a == b)
        return;
    char temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void CalcAllPermutation(char * perm, int from, int to)
{
    if (to < 1)
    {
        return;
    }
    if (from == to)
    {
        for (int i = 0; i <= to; i++)
            printf("%c", perm[i]);
        printf("\n");
    }
    else
    {
        for (int j = from; j <= to; j++)
        {
            swap(&perm[j], &perm[from]);
            CalcAllPermutation(perm, from + 1, to);
            swap(&perm[j], &perm[from]);
        }
    }
}
*/

/* solution_02 */
bool CalcAllPermutation(char* perm, int num)
{
    int i;
    // ①找到排列中最后（最右）一个升序的首位位置i，x = ai
    for (i = num - 2; (i >= 0) && (perm[i] >= perm[i + 1]); --i)
    {
        ;
    }
    // 已经找到所有排列
    if (i < 0)
    {
        return false;
    }
    int k;
    // ②找到排列中第i位右边最后一个比ai 大的位置j，y = aj
    for (k = num - 1; (k > i) && (perm[k] <= perm[i]); --k)
    {
        ;
    }
    // ③交换x，y
    swap(perm[i], perm[k]);
    // ④把第(i+ 1)位到最后的部分翻转
    reverse(perm + i + 1, perm + num);
    return true;
}

int main(int argc, char const *argv[])
{
    /* code */
    char test[] = "abcdefgh";
    CalcAllPermutation(test, 0, strlen(test) - 1);
    return 0;
}