#include<iostream>
#include<vector>
using namespace std;

long long sd(vector<int>& v, int l, int r) {
    long long sum = 0;

    for (int i = l; i < r + 1; ++i) {
        sum += abs(v[(l + r) / 2] - v[i]);
    }

    return sum;
}
long long calcu(vector<int>& v, int l, int r) {
    if (r - l + 1 < 3) {
        if (v[l] > v[r]) {
            int temp = v[l];
            v[l] = v[r];
            v[r] = temp;
        }
        return 0;
    }

    int mid = (l + r) / 2;

    vector<int> vt;
    int a = l,
        b = mid + 1;

    long long first = calcu(v, l, mid),
             second = calcu(v, mid + 1, r),
           first_sd = first + sd(v, mid + 1, r),
          second_sd = second + sd(v, l, mid);

    for (; a < mid + 1; ) {
        if (b > r) break;
        if (v[b] > v[a]) {
            vt.push_back(v[a]);
            a++;
        }
        else {
            vt.push_back(v[b]);
            b++;
        }
    }

    for (; a < mid + 1; ++a) {
        vt.push_back(v[a]);
    }

    for (; b < r + 1; ++b) {
        vt.push_back(v[b]);
    }

    for (int i = 0; i < vt.size(); ++i) {
        v[l + i] = vt[i];
    }

    return min(first_sd, second_sd);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n;  cin >> n;
    vector<int> v;
    for (int _ = 0; _ < n; ++_) {
        int temp;   cin >> temp;
        v.push_back(temp);
    }

    cout << calcu(v, 0, n - 1) << endl;
    return 0;
}