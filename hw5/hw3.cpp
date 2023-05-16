#include <bits/stdc++.h>
using namespace std;

struct node
{
    int f;
    int t;
    int w;
    node(int a, int b, int c)
    {
        f = a;
        t = b;
        w = c;
    }
};

bool smalltobig(node &a, node &b)
{
    return a.w < b.w;
}

bool bigtosmall(node &a, node &b)
{
    return a.w > b.w;
}

int ancient(vector<int> &p, int cur)
{
    if (p[cur] == -1)
        return cur;

    p[cur] = ancient(p, p[cur]);

    return p[cur];
}

void calcu(vector<node> &g, vector<int> &p, vector<int> &d, int &edge, int &sum, bool flag)
{
    for (int i = 0; i < g.size(); ++i)
    {
        node cur = g[i];

        int anf = ancient(p, cur.f),
            ant = ancient(p, cur.t);

        if (anf == ant)
            continue;

        if (d[ant] < d[anf])
        {
            p[ant] = anf;
            d[anf] += d[ant];
        }
        else
        {
            p[anf] = ant;
            d[ant] += d[anf];
        }

        if (flag)
            sum += cur.w;
        else
            sum -= cur.w;
        edge--;
    }
}

int kruskal(vector<node> &g, vector<int> &op, int &v, int &k)
{
    vector<int> p(v, -1), d(v, 1);

    int sum = 0,
        edge = v;

    vector<node> ng, nog;
    for (int j = g.size() - 1; j >= 0; --j)
    {
        node i = g[j];
        if (find(op.begin(), op.end(), i.f) == op.end() && find(op.begin(), op.end(), i.t) == op.end())
        {
            ng.push_back(i);
            continue;
        }

        nog.push_back(i);
    }

    calcu(g, p, d, edge, sum, 1);

    if (edge > 1)
        return -1;

    p.clear();
    p.assign(v, -1);
    d.clear();
    d.assign(v, 1);

    calcu(nog, p, d, edge, sum, 0);
    /*for (int i = 0; i < nog.size(); ++i)
    {
        node cur = nog[i];

        int anf = ancient(p, cur.f),
            ant = ancient(p, cur.t);

        sum -= cur.w;

        if (anf == ant)
            continue;

        if (d[ant] < d[anf])
        {
            p[ant] = anf;
            d[anf] += d[ant];
        }
        else
        {
            p[anf] = ant;
            d[ant] += d[anf];
        }
    }*/

    for (int i = 0; i < ng.size(); ++i)
    {
        node cur = ng[i];

        int anf = ancient(p, cur.f),
            ant = ancient(p, cur.t);

        if (anf == ant)
            continue;

        if (d[ant] < d[anf])
        {
            p[ant] = anf;
            d[anf] += d[ant];
        }
        else
        {
            p[anf] = ant;
            d[ant] += d[anf];
        }

        sum -= cur.w;
    }

    return sum;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    int v, e, k;
    while (cin >> v >> e >> k)
    {
        vector<node> g;
        for (int i = 0; i < e; ++i)
        {
            int f, t, w;
            cin >> f >> t >> w;
            g.push_back(node(min(f, t), max(f, t), w));
        }
        sort(g.begin(), g.end(), bigtosmall);

        vector<int> op;
        for (int i = 0; i < k; ++i)
        {
            int n;
            cin >> n;
            op.push_back(n);
        }
        sort(op.begin(), op.end());

        int ans = kruskal(g, op, v, k);

        if (ans == -1)
            cout << "no\n";
        else
            cout << ans << "\n";
    }

    return 0;
}