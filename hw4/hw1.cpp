#include <bits/stdc++.h>
using namespace std;

bool cmp(string &a, string &b)
{
    string ta = a + b, tb = b + a;
    return ta > tb;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n;
    vector<vector<string>> v;
    v.resize(10);
    for (int i = 0; i < n; ++i)
    {
        int j;
        cin >> j;

        int temp = j;
        while (temp > 9)
            temp /= 10;

        string s = to_string(j);
        v[temp].push_back(s);
    }

    for (int i = 0; i < 10; ++i)
        sort(v[i].begin(), v[i].end(), cmp);

    string ans = "\0";
    for (int i = 9; i >= 0; --i)
    {
        if (i == 0)
        {
            if (ans.size() == 0)
            {
                cout << 0 << "\n";
                break;
            }

            for (int j = 0; j < v[i].size(); ++j)
                ans += "0";

            continue;
        }

        for (int j = 0; j < v[i].size(); ++j)
            ans += v[i][j];
    }

    cout << ans << "\n";

    return 0;
}
