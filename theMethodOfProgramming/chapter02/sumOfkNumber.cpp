#include <iostream>
#include <list>

using namespace std;

list<int> list1;

void SumOfkNumber(int sum, int n)
{
    // 递归出口
    if (n <= 0 || sum <= 0)
        return;

    // 输出找到的结果
    if (sum == n)
    {
        // 反转list
        list1.reverse();
        for (list<int>::iterator iter = list1.begin(); iter != list1.end(); iter++)
            cout << *iter << " + ";
        cout << n << endl;
        list1.reverse();    //此处还需反转回来
    }

    list1.push_front(n);    //典型的01背包问题
    SumOfkNumber(sum - n, n - 1);    //“放”n，前n-1个数“填满”sum-n
    list1.pop_front();
    SumOfkNumber(sum, n - 1);     //不“放”n，n-1个数“填满”sum
}

int main(int argc, char const *argv[])
{
    SumOfkNumber(5, 5);
    return 0;
}
