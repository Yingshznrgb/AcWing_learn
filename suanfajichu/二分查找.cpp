// 整数二分
// 有两个模板，写的时候先不考虑用哪个
// 根据答案所在的区间判断下一个区间应该怎么更新
// 如果l=mid，那么补上mid=l+r+1>>1;
// 如果r=mid，那么只要mid=l+r>>1;
// 二分一定有解，无解的情况是题目的问题
#include <iostream>
using namespace std;

const int N = 1e6 + 10;
int m, n;
int q[N];

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d", &q[i]);

    while (m--)
    {
        int x;
        scanf("%d", &x);
        int l = 0, r = n - 1;
        while (l < r)
        {
            int mid = l + r >> 1;
            if (q[mid] >= x)
                r = mid; // （从左往右看）先找到第一个满足大于等于x的数
            else
                l = mid + 1;
        }
        if (q[l] != x)
            printf("-1 -1\n"); // 如果无解
        else
        {
            printf("%d ", l); // 打印的时候l=r
            int l = 0, i = n - 1;
            while (l < r)
            {
                int mid = l + r + 1 >> 1;
                if (q[mid] <= x)
                    l = mid; // （从左往右看）再找最后一个满足小于等于x的数
                else
                    r = mid - 1;
            }
            printf("%d\n", l);
        }
    }

    return 0;
}

// 浮点数二分，不用考虑边界问题
//  while(r-l>1e-8)  //答案要求保留（6，5，4）位，就（-8，-7，-6）次方
//  {
//      double mid = (l + r)/2;
//      if(mid * mid >= x)r = mid;
//      else l = mid;
//  }