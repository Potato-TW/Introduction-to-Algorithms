#include<bits/stdc++.h>
#define long long int int
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n;  cin >> n;

    vector<int> coins;
    for (int i = 0; i < n; ++i) {
        int coin;   cin >> coin;
        coins.push_back(coin);
    }

    int m;  cin >> m;
    vector<pair<int, vector<int>>> customer;
    for (int i = 0; i < m; ++i) {
        int cost;   cin >> cost;
        vector<int> takeout;
        for (int j = 0; j < n; ++j) {
            int coin;   cin >> coin;
            takeout.push_back(coin);
        }

        customer.push_back({ cost, takeout });
    }

    vector<int> rec, ans;
    rec.push_back(0);
    for(int i=0;i<100005;++i){
        rec.push_back(INT_MAX);
    }
    for (int j = 0; j < 100005; ++j) {
        for (int i = coins.size() - 1; i >= 0; --i) {
            if (coins[i] < j + 1)
                rec[j] = min(rec[j], rec[j - coins[i]] + 1);
        }
    }

    for (auto _ : customer) {
        int cost = 0;
        for (int i = 0; i < _.second.size(); ++i) {
            cost += (coins[i] * _.second[i]);
        }
        cost -= _.first;
        // cout<<"cost: "<<cost<<endl;

        if (cost <= 0) {
            cout << 0 << endl;
            continue;
        }

    //     int recsize = rec.size();
    //     for (int i = recsize; i < cost + 1; ++i) {
    //         rec.push_back(INT_MAX);
    //     }
    //     rec[0] = 0;
    //     for (int j = recsize; j < cost + 1; ++j) {
    //         for (int i = coins.size() - 1; i >= 0; --i) {
    //             if (coins[i] < j + 1)
    //                 rec[j] = min(rec[j], rec[j - coins[i]] + 1);
    //         }
    //     }
        // for(auto i:rec) cout<<i<<endl;

        cout << rec[cost] << endl;
    }

    // cout << "----------\n";
    // for (auto i : rec) cout << i << " ";
    return 0;
}

/*
4
10 5 2 1
1
5 1 0 0 0
*/
