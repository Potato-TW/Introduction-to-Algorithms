#include <bits/stdc++.h>
#define pss pair<short, short>
using namespace std;

int findcenter(int &l)
{
    return (l / 2) * (l + 1);
}

int span(vector<vector<short>> &g, int i, int j, int &l, int &r)
{
    int sum = 0;
    int row = r * 2 + 1;

    queue<pss> q;
    q.push({i, j});
    while (!q.empty())
    {
        pss temp = q.front();
        q.pop();

        sum++;
        g[temp.first][temp.second] = 2;

        for (int a = -1; a < 2; ++a)
        {
            for (int b = -1; b < 2; ++b)
            {
                if (abs(a + b) == 2 || a + b == 0)
                    continue;

                if (temp.first + a < 0 || temp.first + a > l - 1)
                    continue;
                if (temp.second + b < 0 || temp.second + b > l - 1)
                    continue;

                if (g[temp.first + a][temp.second + b] == 1)
                    q.push({temp.first + a, temp.second + b});

                g[temp.first + a][temp.second + b] = 2;
            }
        }
    }

    return sum;
}

int calcu(vector<vector<short>> &g, int &l, int &r)
{
    pss c = {l / 2, l / 2};

    // 0->tree
    // 1->grass
    // 2->used

    int row = r * 2 + 1;
    int ans = 0;
    for (int i = -r; i < r + 1; ++i)
    {
        for (int j = -r; j < r + 1; ++j)
        {
            if (c.first + i < 0 || c.first + i > l - 1)
                continue;
            if (c.second + j < 0 || c.second + j > l - 1)
                continue;

            if (g[c.first + i][c.second + j] == 1)
            {
                int temp = span(g, c.first + i, c.second + j, l, r);
                if (temp > ans)
                    ans = temp;
            }

            g[c.first + i][c.second + j] = 2;
        }
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    for (int _ = 0; _ < n; ++_)
    {
        int l, r;
        cin >> l >> r;

        vector<vector<short>> g(l, vector<short>(l, 0));

        for (int i = 0; i < l; ++i)
        {
            for (int j = 0; j < l; ++j)
            {
                char input;
                cin >> input;

                if (input == '_')
                    g[i][j] = 1;
            }
        }

        cout << calcu(g, l, r) << "\n";
    }

    return 0;
}