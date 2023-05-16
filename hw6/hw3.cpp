#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, m, c, r;
vector<int> path, flow, timeslot, visited;
vector<vector<int>> v, ava;

void initial()
{
    for (int i = 0; i < m; ++i)
    {
        int num, t;
        cin >> num >> t;

        vector<int> temp;
        for (int j = 0; j < t; ++j)
        {
            int input;
            cin >> input;
            temp.push_back(input);
        }

        ava.push_back(temp);
    }

    v.resize(n);
    path.assign(m, -1);
    flow.assign(n, 0);
}

void end()
{
    v.clear();
    ava.clear();
    path.clear();
    flow.clear();
    visited.clear();
    timeslot.clear();
}

bool maxflow(int cur)
{
    for (int i = 0; i < timeslot.size(); ++i)
    {
        if (visited[timeslot[i]] == 1)
            continue;

        if (find(ava[cur].begin(), ava[cur].end(), timeslot[i]) == ava[cur].end())
            continue;

        visited[timeslot[i]] = 1;

        if (flow[timeslot[i]] < c)
        {
            if (path[cur] != -1)
            {
                auto it = find(v[timeslot[i]].begin(), v[timeslot[i]].end(), i);
                if (it != v[timeslot[i]].end())
                    v[timeslot[i]].erase(it);
                --flow[path[cur]];
            }

            v[timeslot[i]].push_back(cur);

            path[cur] = timeslot[i];
            ++flow[timeslot[i]];

            return 1;
        }

        for (int j = 0; j < v[timeslot[i]].size(); ++j)
        {
            // if (j > -1)
            // {
            if (find(v[timeslot[i]].begin(), v[timeslot[i]].end(), j) == v[timeslot[i]].end())
                continue;

            if (!maxflow(j))
                continue;
            // }

            // if (flow[timeslot[i]] >= c)
            //     continue;

            if (path[cur] != -1)
            {
                auto it = find(v[timeslot[i]].begin(), v[timeslot[i]].end(), i);
                if (it != v[timeslot[i]].end())
                    v[timeslot[i]].erase(it);
                --flow[path[cur]];
            }

            v[timeslot[i]].push_back(cur);

            path[cur] = timeslot[i];
            ++flow[timeslot[i]];

            return 1;
        }
    }

    return 0;
}

int ans()
{
    int sum = 0;
    for (auto i : flow)
        sum += i;

    return m - sum;
}

int32_t main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    while (cin >> n >> m >> c >> r)
    {
        initial();

        for (int i = 0; i < r; ++i)
        {
            int t;
            cin >> t;

            for (int j = 0; j < t; ++j)
            {
                int slot;
                cin >> slot;
                timeslot.push_back(slot);
            }

            for (int j = 0; j < m; ++j)
            {
                visited.assign(n, 0);
                maxflow(j);
            }

            cout << ans() << "\n";

            timeslot.clear();
        }

        end();
    }

    return 0;
}