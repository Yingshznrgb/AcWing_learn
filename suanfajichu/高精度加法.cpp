#include <iostream>
#include <vector>
using namespace std;

string a, b;
vector<int> A, B;

vector<int> add(vector<int> &A, vector<int> &B)
{
    vector<int> c;
    int t = 0; // t既计算当前位的值，又计算进位
    for (int i = 0; i < A.size() || i < B.size(); i++)
    {
        if (i < A.size())
            t += A[i];
        if (i < B.size())
            t += B[i];
        c.push_back(t % 10);
        t = t / 10;
    }
    if (t)
        c.push_back(1);
    return c;
}

int main()
{
    cin >> a >> b;
    //倒序存入
    for (int i = a.size() - 1; i >= 0; i--)
        A.push_back(a[i] - '0');
    for (int i = b.size() - 1; i >= 0; i--)
        B.push_back(b[i] - '0');

    auto c = add(A, B);

    //倒序输出
    for (int i = c.size() - 1; i >= 0; i--)
        printf("%d", c[i]);
    return 0;
}