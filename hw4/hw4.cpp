#include <bits/stdc++.h>
using namespace std;

struct node
{
    int s;
    int e;
    node(int a, int b) : s(a), e(b){};
};

bool cmp(node &a, node &b)
{
    if (a.e != b.e)
        return a.e < b.e;
    else
        return a.s > b.s;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n;

    vector<node> rec;
    for (int i = 0; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;

        node temp = node(a, b);
        rec.push_back(temp);
    }

    sort(rec.begin(), rec.end(), cmp);

    vector<node> ans;

    int prestart = -1;
    for (int i = 0; i < rec.size(); ++i)
    {
        node cur = rec[i];
        if (cur.s >= prestart)
        {
            ans.push_back(cur);
            prestart = cur.e;
        }
    }

    for (int i = 0; i < ans.size(); ++i)
        cout << ans[i].s << " " << ans[i].e << "\n";

    return 0;
}
