#include<iostream>
#include<unordered_map>
#include<queue>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k; cin >> n>>k;
	unordered_map<int, int> for_time;	// mean value
	for (int i = 0; i < n; ++i) {
		int key;	cin >> key;
		++for_time[key];
	}

	priority_queue<pair<int, int>> pq;	// time, key
	for (auto i = for_time.begin(); i != for_time.end(); ++i) {
		pq.push({i->second, i->first});
	}

	for(int i=0;i<k-1;++i){
		pq.pop();
	}

	cout<<pq.top().second<<endl;

	return 0;
}