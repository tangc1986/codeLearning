#include <stdio.h>

#define true 1
#define false 0

/* solution_tc
int StringContains(char *strA, char *strB)
{
    unsigned int lenA = strlen(strA);
    unsigned int lenB = strlen(strB);
    unsigned int indexA = 0;
    unsigned int indexB = 0;

    for (indexB = 0; indexB < lenB; indexB++)
    {
        for (indexA = 0; indexA < lenA; indexA++)
        {
            if (strA[indexA] == strB[indexB])
                break;
        }
        if (indexA >= lenA)
            return false;
    }

    return true;

}
*/

/* solution_01
bool StringContains(string &a, string &b)
{
    for (int i = 0; i < b.length(); ++i)
    {
        int j;
        for (j = 0; (j < a.length()) && (a[j] != b[i]); ++j)
            ;
        if (j >= a.length())
            return false;
    }
    return true;
}
 */

int main(int argc, char const *argv[])
{
    /* code */
    char test_chr_A[] = "ABCD";
    char test_chr_B[] = "AA";

    if (StringContains(test_chr_A,test_chr_B))
        printf("StringContains is true\n");
    else
        printf("StringContains is false\n");

    return 0;
}