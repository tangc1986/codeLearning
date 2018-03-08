#include <stdio.h>

void moveChars(char *str, unsigned int n)
{
    unsigned int len = strlen(str);
    unsigned int step = n % len;
    unsigned int i = 0, j = 0;
    char tmp_chr = '\0';
    for (i = step; i > 0; i--)
    {
        tmp_chr = str[0];
        for (j = 1; j < len; j++)
        {
            str[j-1] = str[j];
        }
        str[j-1] = tmp_chr;
    }
}


int main(int argc, char const *argv[])
{
    /* code */
    char test_chr[] = "abcdef";
    printf("source string is %s\n", test_chr);
    moveChars(test_chr, 2);
    printf("result string is %s\n", test_chr);

    return 0;
}