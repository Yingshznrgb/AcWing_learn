// 思想：分治
// 选分隔数，左、右端点，中点，随机值。
// 调整区间
// 递归处理左右两段

#include <iostream>
#include <time.h>
using namespace std;

const int N = 1e6 + 10;

int n;
int q[N];

void quick_sort(int q[], int l, int r)
{
    if (l >= r)
        return;
    int rnd_idx=rand()%(r - l + 1) + l; //取随机值
    swap(q[l],q[rnd_idx]); 

    int x = q[l], i = l - 1, j = r + 1;
    while (i < j)
    {
        do
            i++;
        while (q[i] < x);
        do
            j--;
        while (q[j] > x);
        if (i < j)
            swap(q[i], q[j]);
    }

    quick_sort(q, l, j); //左半段
    quick_sort(q, j + 1, r);//右半段
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &q[i]);

    quick_sort(q, 0, n - 1);

    for (int i = 0; i < n; i++)
        printf("%d ", q[i]);
}