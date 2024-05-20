
// 用二进制数表示对第一行的操作
// 对第一行进行枚举
// 后面每一行取决于前一行的状态
// 判断能否成立

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 6;
int n;
char g[N][N], mem[N][N];
int dx[5] = {-1, 0, 1, 0, 0}, dy[5] = {0, 1, 0, -1, 0};

void turn(int x, int y)
{
    for (int i = 0; i < 5; i++)
    {
        int a = x + dx[i], b = y + dy[i];
        if (a < 0 || a > 6 || b < 0 || b > 6)
            continue;
        g[a][b] ^= 1;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        for (int i = 0; i < 5; i++)
            cin >> g[i]; // 读入数据

        int res = 10;
        memcpy(mem, g, sizeof g);
        for (int op = 0; op < 32; op++)
        {
            int step = 0;
            for (int i = 0; i < 5; i++)
                if (op >> i & 1)
                {
                    step++;
                    turn(0, i);
                }

            for (int i = 0; i < 4; i++)
                for (int j = 0; j < 5; j++)
                {
                    if (g[i][j] == '0')
                    {
                        step++;
                        turn(i + 1, j);
                    }
                }

            bool dark = false;
            for (int i = 0; i < 5; i++)
                if (g[4][i] == '0')
                {
                    dark = true;
                    break;
                }
            if (!dark)
                res = min(res, step);
            memcpy(g, mem, sizeof mem);
        }

        if (res > 6)
            cout << -1 << endl;
        else
            cout << res << endl;
    }
    return 0;
}
