#include <bits/stdc++.h>
using namespace std;

int calcu(vector<int> &v)
{
    vector<int> rec(v.size(), INT_MAX);
    rec[0] = 0;
    rec[1] = 0;
    for (int i = 1; i < v.size(); ++i)
    {
        for (int j = i + 1; j < i + v[i] + 1; ++j)
        {
            if (j > v.size())
                break;

            rec[j] = min(rec[i] + 1, rec[j]);
        }

        // for (auto j : rec)
        // {
        //     if (j == INT_MAX)
        //     {
        //         cout << -1 << " ";
        //         continue;
        //     }
        //     cout << j << " ";
        // }
        // cout << endl;
    }

    return rec[v.size()-1];
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n;

    vector<int> v;
    v.push_back(0);
    for (int i = 0; i < n; ++i)
    {
        int k;
        cin >> k;
        v.push_back(k);
    }

    cout << calcu(v);

    return 0;
}