#include <stdio.h>


/* solution_tc 
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
*/

/* solution_01
void LeftShiftOne(char* s, int n)
{
    char t = s[0];      //保存第一个字符     
    for (int i = 1; i < n; i++)     
    {
        s[i - 1] = s[i];
    }
    s[n - 1] = t;
}

void LeftRotateString(char* s, int n, int m)
{
    while (m--)
    {
        LeftShiftOne(s, n);
    }
}
*/

// solution_02
void ReverseString(char *s, int from, int to)
{
    while (from < to)
    {
        char t = s[from];
        s[from++] = s[to];
        s[to--] = t;
    }
}

void LeftRotateString(char *s, int n, int m)
{
    m %= n;
    ReverseString(s, 0, m-1);
    ReverseString(s, m, n-1);
    ReverseString(s, 0, n-1);
}

int main(int argc, char const *argv[])
{
    /* code */
    char test_chr[] = "tangchao";
    printf("source string is %s\n", test_chr);
    LeftRotateString(test_chr, 8, 3);
    printf("result string is %s\n", test_chr);

    return 0;
}