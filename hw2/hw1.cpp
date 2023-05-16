#include<iostream>
#include<map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;  cin >> n;
    map<int, int>map;
    for (int i = 0; i < n; ++i) {
        int sum = 0;
        for (int j = 0; j < 5; ++j) {
            int in; cin >> in;
            sum += in;
        }

        ++map[sum];
    }

    for (auto i = map.rbegin(); i != map.rend();++i) {
        for (int j = 0; j < i->second; ++j) {
            cout << i->first << "\n";
        }
    }


    return 0;
}

//用map存有幾次 才不會存重複值存到爆掉