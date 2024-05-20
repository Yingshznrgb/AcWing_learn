/*
// 1，枚举1~9全排列
// 2，枚举a,b,c的位数
// 3，判断等式是否成立
#include <iostream>

using namespace std;

const int N = 10;
int n;
int st[N];
bool used[N];
int A, B, C;
int cnt = 0;

int calc(int l, int r)
{
  int res = 0;
  for (int i = l; i <= r; i++)
  {
    res = res * 10 + st[i];
  }
  return res;
}

void dfs2()
{
  for (int i = 0; i < 7; i++)
  {
    for (int j = i + 1; j < 8; j++)
    {
      int a = calc(0, i);
      int b = calc(i + 1, j);
      int c = calc(j + 1, 8);
      if (a == 0 || b == 0 || c == 0)
        return;
      // 除法转化为加减乘来计算
      if (a * c + b == c * n)
      {
        cnt++;
      }
    }
  }
  return;
}

void dfs1(int u)
{
  if (u == 9)
  {
    dfs2();
    return;
  }

  for (int i = 1; i <= 9; i++)
  {
    if (!used[i])
    {
      used[i] = true;
      st[u] = i;
      dfs1(u + 1);

      used[i] = false;
      st[u] = 0;
    }
  }
}

int main()
{
  cin >> n;

  dfs1(0);

  cout << cnt;

  return 0;
}
*/

#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

const int N=5;
int ans;
char g[N][N],backup[N][N];
int st[10010][2];//记录操作顺序
int dx[13]={-3,-2,-1,0,1,2,3,0,0,0,0,0,0},dy[13]={0,0,0,0,0,0,0,-1,-2,-3,1,2,3};

void turn(int x,int y)
{
  x-=1,y-=1;
    for(int i=0;i<13;i++)
    {
        int a=x+dx[i],b=y+dy[i];
        if(a<0||a>3||b<0||b>3)continue;
        if(g[a][b]=='+')
        g[a][b]='-';
        else g[a][b]='+';
    }
}

int main()
{
    for(int i=0;i<4;i++)cin>>g[i];

    turn(1,1);
    
    turn(1,3);
    turn(1,4);
    turn(4,1);
    turn(4,3);
    turn(4,4);
    

    for(int i=0;i<4;i++)cout<<g[i]<<endl;
}