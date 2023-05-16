#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool cmp(pair<string, vector<int>>&, pair<string, vector<int>>&);

int main() {
    // hwie
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;  cin >> n;
    vector<vector<int>> order;
    for (int i = 0; i < 4; i++) {
        string key;  cin >> key;
        vector<int> vt;
        for (int j = 0; j < 4; j++) {
            if (key[j] == 'H')  vt.push_back(0);
            if (key[j] == 'W')  vt.push_back(1);
            if (key[j] == 'I')  vt.push_back(2);
            if (key[j] == 'E')  vt.push_back(3);
        }
        order.push_back(vt);
    }

    vector<vector<pair<string, vector<int>>>> list(4);

    for (int i = 0; i < n; i++) {
        string name;    cin >> name;
        int max_score = 0, highest = 0;

        int scores[4];
        for (int j = 0; j < 4; j++) {
            cin >> scores[j];

            if (scores[j] > max_score) {
                max_score = scores[j];
                highest = j;
            }
        }

        vector<int> ordered_scores(4);
        for (int j = 0; j < 4; j++) {
            ordered_scores[j] = scores[order[highest][j]];
        }

        pair<string, vector<int>> psv = { name, ordered_scores };
        list[highest].push_back(psv);
    }
    
    for (int i = 0; i < 4; i++) {
        sort(list[i].begin(), list[i].end(), cmp);
        cout << "Group " << (char)(i + 'A') << ":";
        if (list[i].empty()) {
            cout << " No Audience\n" ;
            continue;
        }
        cout << "\n";

        for (auto it : list[i]) {
            cout << it.first << "\n";
        }
    }
    
    return 0;
}


bool cmp(pair<string, vector<int>>& a, pair<string, vector<int>>& b) {

    if (a.second[0] != b.second[0]) return a.second[0] > b.second[0];
    if (a.second[1] != b.second[1]) return a.second[1] > b.second[1];
    if (a.second[2] != b.second[2]) return a.second[2] > b.second[2];
    if (a.second[3] != b.second[3]) return a.second[3] > b.second[3];
    return a.first < b.first;

}