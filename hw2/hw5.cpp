#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

long long calcu(vector<long long>& v, long long& a, long long& b, long long l, long long r) {
    long long siz = r - l + 1,
              mid = (l + r) / 2;

    long long diff = upper_bound(v.begin(), v.end(), r) - lower_bound(v.begin(), v.end(), l);

    if (l == r) {
        if (diff == 0) {
            return a;
        }
        else
            return b * diff;
    }
    if (diff == 0) {
        return a;
    }
    
    
    long long now = b * siz * diff,
              div_half= calcu(v, a, b, l, mid) + calcu(v, a, b, mid + 1, r);
    if (div_half > now)
        return now;
    else
        return div_half;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    long long n, k, a, b; cin >> n >> k >> a >> b;

    vector<long long> v;
    for (long long i = 0; i < k; ++i) {
        long long key;    cin >> key;
        v.push_back(key);
    }

    sort(v.begin(), v.end());
    
    cout << calcu(v, a, b, 1, n)<<endl;
    return 0;
}