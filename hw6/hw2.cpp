#include <bits/stdc++.h>
using namespace std;

struct node
{
    int t;
    int w;
    node(int& a, int& b)
    {
        t = a;
        w = b;
    }
};

struct pqcmp
{
    bool operator()(node& a, node& b)
    {
        return a.w > b.w;
    }
};

int dijkstra(vector<int>& loc, vector<int>& shelter, vector<vector<node>>& g, int& start)
{
    vector<int> parent(loc.size(), -1);
    vector<int> state(loc.size(), INT_MAX);
    state[start] = loc[start];

    priority_queue<node, vector<node>, pqcmp> pq;
    pq.push(node(start, state[start]));

    while (!pq.empty())
    {
        node cur = pq.top(); // {now=i, state[i]}
        pq.pop();

        if (find(shelter.begin(), shelter.end(), cur.t) != shelter.end())
            return state[cur.t];

        for (int i = 0; i < g[cur.t].size(); ++i)
        {
            node temp = g[cur.t][i];
            int cal = temp.w + cur.w + loc[temp.t];

            if (cal < state[temp.t])
            {
                state[temp.t] = cal;
                parent[temp.t] = cur.t;
                pq.push(node(temp.t, state[temp.t]));
            }
        }
    }

    return -1;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    int l, r, s;
    while (cin >> l >> r >> s)
    {
        vector<int> loc;
        vector<int> shelter;
        vector<vector<node>> g;
        int start;

        for (int i = 0; i < l; ++i)
        {
            int rad;
            cin >> rad;
            loc.push_back(rad);
        }

        g.resize(l);
        for (int i = 0; i < r; ++i)
        {
            int f, t, w;
            cin >> f >> t >> w;
            g[f].push_back(node(t, w));
            g[t].push_back(node(f, w));
        }

        for (int i = 0; i < s; ++i)
        {
            int shel;
            cin >> shel;
            shelter.push_back(shel);
        }

        cin >> start;

        cout << dijkstra(loc, shelter, g, start) << "\n";
    }

    return 0;
}