#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n;  cin >> n;
    long long l, r; cin >> l >> r;

    vector<long long> v;
    for (int i = 0; i < n; ++i) {
        long long key;    cin >> key;
        v.push_back(key);
    }

    sort(v.begin(), v.end());

    long long sum = 0;
    for (int i = 0; i < v.size(); ++i){ 
        long long ceil_l, ceil_r;
        if(l%v[i]==0){
            ceil_l=l/v[i];
        }
        else{
            ceil_l=l/v[i]+1;
        }
            
        sum += upper_bound(v.begin() + i+1, v.end(), r/v[i])-lower_bound(v.begin() + i+1, v.end(), ceil_l);
    }

    cout << sum << endl;

    return 0;
}
