//先确定好分界点，然后递归排序左右两边
//再进行归并，合二为一(双指针)
//归并：nlogn 快排：（最大）n^2  （平均）nlogn
#include<iostream>
#include<vector>
using namespace std;

const int N = 1e6+10;
int n;
int q[N],temp[N];

void merge_sort(int q[],int l,int r)
{
    if(l >= r)return ;

    int mid = (l + r) >> 1;

    merge_sort(q,l,mid);merge_sort(q,mid+1,r);

    int k = 0, i=l, j = mid + 1; //相当于双指针
    while(i <= mid && j <=r) 
    {
        if(q[i] <= q[j]) temp[k ++]= q[i ++];
        else temp[k ++] = q[j ++];
    }
    while(i <= mid) temp[k ++] = q[i ++];
    while(j <= r) temp[k ++] = q[j ++];

    for(i = l, j = 0; i <=r; i ++,j ++) q[i] = temp[j];
}

int main()
{
    scanf("%d",&n);
    for( int i = 0 ; i < n ; i++)scanf("%d",&q[i]);

    merge_sort(q,0,n-1);

    for( int i = 0 ; i < n ; i++)printf("%d ",q[i]);
    
    return 0;
}