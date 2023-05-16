// #include<iostream>
// #include<vector>
#include<bits/stdc++.h>
using namespace std;

void calcu(vector<int>& v, vector<int>& rec, int cur) {
    if (cur > v.size())    return;

    int a = rec[cur - 1] + v[cur - 1],
        b = rec[cur - 2] + v[cur - 2],
        c = min(a, b);

    rec[cur] = c;

    calcu(v, rec, cur + 1);
}


int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;  cin >> n;

    vector<int> v;
    for (int i = 0; i < n; ++i) {
        int input;  cin >> input;
        v.push_back(input);
    }

    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }

    vector<int> rec(n + 1, 0);
    calcu(v, rec, 2);
    cout << rec[n] << endl;


    return 0;
}