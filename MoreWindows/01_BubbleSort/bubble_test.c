#include <stdio.h>

int main()
{
    int test[] = {6,3,8,2,9,1};
    printf("Original Array: ");
    print_array(test, sizeof(test)/sizeof(int));
    BubbleSort(test, sizeof(test)/sizeof(int));
    printf("Sorted Array: ");
    print_array(test, sizeof(test)/sizeof(int));
    return 0;
}
