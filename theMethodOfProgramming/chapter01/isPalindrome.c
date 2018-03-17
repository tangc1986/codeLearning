#include <stdio.h>
#include <stdbool.h>

/* solution_tc */
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

/* solution_02 */
bool IsPalindrome2(const char *s, int n)
{
    if (!s || n < 1)
        return false;
    const char * first, * second;

    int m = ((n >> 1) - 1) >= 0 ? (n >> 1) - 1 : 0;
    first = s + m;
    second = s + n - 1 - m;

    while (first >= s)
    {
        if (*first != *second)
        {
            return false;
        }
        --first;
        ++second;
    }
    return true;
}

// int main(int argc, char const *argv[])
// {
//     /* code */
//     char test_chr[] = "1234567987654321";

//     if (IsPalindrome(test_chr, strlen(test_chr)))
//         printf("%s string is palindrome.\n", test_chr);
//     else
//         printf("%s string is not palindrome.\n", test_chr);

//     return 0;
// }

int main(int argc, char const *argv[])
{
    /* code */
    int i = 0;
    while(1)
    {
        scanf("%d", &i);
        int j = ((i >> 1) - 1) >= 0 ? (i >> 1) - 1 : 0;
        printf("%d\n", j);
    }
    return 0;
}