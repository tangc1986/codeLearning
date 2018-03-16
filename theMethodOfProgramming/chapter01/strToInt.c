#include <stdio.h>

#define true 1
#define false 0

/* solution_tc */
int StrToInt(const char *str)
{
    int length = strlen(str);
    int ret = 0;
    int i = 0;

    for (i = 0; i < length; i++)
    {
        if (str[i] < '0' || str[i] > '9')
            return -1;
        ret = ret * 10 + (str[i]-'0');
    }

    return ret;
}

int main(int argc, char const *argv[])
{
    /* code */
    char test_chr[] = "124325123123123";

    printf("target string is %s\n", test_chr);
    printf("result number is %d\n", StrToInt(test_chr));

    return 0;
}