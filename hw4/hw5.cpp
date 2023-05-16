#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    long long int n;
    cin >> n;

    set<int> s;
    for (long long int i = 0; i < n; ++i)
    {
        long long int k;
        cin >> k;
        s.insert(k);
    }

    long long int tar;
    cin >> tar;

    long long int count = 0, i = 1, ans = 0;
    while (count != tar)
    {
        if (s.find(i) == s.end())
        {
            ans += i;
            count++;
        }
        i++;
    }

    cout << ans << endl;

    return 0;
}