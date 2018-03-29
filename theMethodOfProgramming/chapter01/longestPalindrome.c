#include <stdio.h>
#include <stdbool.h>

/* solution_tc  O(n^2)??
bool IsPalindrome(const char *s, int n)
{
    if (!s || n < 1)
        return false;

    int i, j;

    for (i = 0, j = n-1; i < j; i++, j--)
    {
        if (s[i] != s[j])
            return false;
    }

    return true;
}

int LongestPalindrome(const char *s, int n)
{
    int i = 0, len = 0, max_len = 0, max_i = 0;

    for(i = 0; i < n-1; i++)
    {
        for(len = 1; len < n-i; len++)
        {
            if (IsPalindrome(s + i, len) && len > max_len)
            {
                max_len = len;
                max_i = i;
            }
        }
    }

    printf("max_i = %d\n", max_i);

    return max_len;
}
*/

/* solution_01 */
int LongestPalindrome(const char *s, int n)
{
    int i, j, max, c;
    if (s == 0 || n < 1)
        return 0;
    max = 0;
    for (i = 0; i < n; ++i)
    { // i is the middle point of the palindrome
        for (j = 0; (i - j >= 0) && (i + j < n); ++j)
        { // if the length of the palindrome is odd
            if (s[i - j] != s[i + j])
                break;
            c = j * 2 + 1;
        }
        if (c > max)
            max = c;
        for (j = 0; (i - j >= 0) && (i + j + 1 < n); ++j)
        { // for the even case
            if (s[i - j] != s[i + j + 1])
                break;
            c = j * 2 + 2;
        }
        if (c > max)
            max = c;
    }
    return max;
}

int main(int argc, char const *argv[])
{
    char *test = "asdkjaskdkkaskdiaidkasdjaskdjasdk";
    printf("max_len = %d\n", LongestPalindrome(test, strlen(test)));

    return 0;
}


