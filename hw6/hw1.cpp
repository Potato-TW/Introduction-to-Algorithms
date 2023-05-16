#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

struct node
{
    int f;
    int t;
    node(int &a, int &b)
    {
        f = a;
        t = b;
    }
};

int bfs(vector<vector<int>> &g)
{
    int max_ = 0;

    for (int i = 0; i < g.size(); ++i)
    {
        vector<int> dis(g.size(), -1);
        vector<int> par(g.size(), 0);
        vector<int> vis(g.size(), 0);
        queue<int> q;
        q.push(i);
        int count = 0;

        while (!q.empty())
        {
            int cur = q.front();
            q.pop();

            vis[cur] = 1;
            count++;

            dis[cur] = dis[par[cur]] + 1;

            if (dis[cur] > max_)
                max_ = dis[cur];

            for (auto i : g[cur])
            {
                if (vis[i] == 1)
                    continue;

                q.push(i);
                par[i] = cur;
                vis[i] = 1;
            }
        }
        if (count != g.size())
            return -1;
    }

    return max_;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    int n;
    while (cin >> n)
    {
        unordered_map<string, int> map;
        vector<vector<int>> g;
        vector<node> temp;
        int count = 0;
        for (int _ = 0; _ < n; ++_)
        {
            string a, b;
            cin >> a >> b;

            if (map.find(a) == map.end())
            {
                map[a] = count;
                count++;
            }
            if (map.find(b) == map.end())
            {
                map[b] = count;
                count++;
            }

            temp.push_back(node(map[a], map[b]));
        }

        g.resize(count);
        for (auto i : temp)
        {
            g[i.f].push_back(i.t);
            g[i.t].push_back(i.f);
        }

        cout << bfs(g) << "\n";
    }

    return 0;
}