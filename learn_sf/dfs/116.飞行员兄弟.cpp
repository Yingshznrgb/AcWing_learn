// 考虑四层循环

#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int N = 5;
int ans;
char g[N][N], backup[N][N];
int st[10010][2];                                                                                             // 记录操作顺序
int dx[13] = {-3, -2, -1, 0, 1, 2, 3, 0, 0, 0, 0, 0, 0}, dy[13] = {0, 0, 0, 0, 0, 0, 0, -1, -2, -3, 1, 2, 3}; // 偏移量

void turn(int x, int y) // 操作
{
    for (int i = 0; i < 13; i++)
    {
        int a = x + dx[i], b = y + dy[i];
        if (a < 0 || a > 3 || b < 0 || b > 3)
            continue;
        if (g[a][b] == '+')
            g[a][b] = '-';
        else
            g[a][b] = '+';
    }
}

void pri(int i)
{
    cout << i << endl;
    for (int j = 0; j < i; j++)
        cout << st[j][0] << " " << st[j][1] << endl;
}

int main()
{
    for (int i = 0; i < 4; i++)
        cin >> g[i];

    memcpy(backup, g, sizeof g);
    for (int a = 0; a < 16; a++) // 第一行
    {
        int step = 0;
        for (int i = 0; i < 4; i++)
        {
            if (a >> i & 1)
            {
                st[step][0] = 1;
                st[step][1] = i + 1;
                step++;
                turn(0, i);
            }
        }

        for (int b = 0; b < 16; b++) // 第二行
        {
            for (int i = 0; i < 4; i++)
            {
                if (b >> i & 1)
                {
                    st[step][0] = 2;
                    st[step][1] = i + 1;
                    step++;
                    turn(1, i);
                }
            }

            for (int c = 0; c < 16; c++) // 第三行
            {
                for (int i = 0; i < 4; i++)
                {
                    if (c >> i & 1)
                    {
                        st[step][0] = 3;
                        st[step][1] = i + 1;
                        step++;
                        turn(2, i);
                    }
                }

                for (int d = 0; d < 16; d++) // 第四行
                {
                    for (int i = 0; i < 4; i++)
                    {
                        if (d >> i & 1)
                        {
                            st[step][0] = 4;
                            st[step][1] = i + 1;
                            step++;
                            turn(3, i);
                        }

                        bool flag = true; // 判断
                        for (int i = 0; i < 4; i++)
                            for (int j = 0; j < 4; j++)
                                if (g[i][j] == '+')
                                    flag = false;
                        if (flag)
                        {
                            pri(step);
                            return 0;
                        }

                        memcpy(g, backup, sizeof backup);
                    }
                }
            }
        }
    }
}