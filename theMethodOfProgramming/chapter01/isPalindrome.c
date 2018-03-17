#include <stdio.h>
#include <stdbool.h>

/* solution_tc */
bool IsPalindrome(const char *s, int n)
{
    int i, j;

    for (i = 0, j = n-1; i < j; i++, j--)
    {
        if (s[i] != s[j])
            return false;
    }

    return true;
}

int main(int argc, char const *argv[])
{
    /* code */
    char test_chr[] = "1234567987654321";

    if (IsPalindrome(test_chr, strlen(test_chr)))
        printf("%s string is palindrome.\n", test_chr);
    else
        printf("%s string is not palindrome.\n", test_chr);

    return 0;
}