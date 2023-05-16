#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<queue>
#include<climits>
using namespace std;

long long sd(vector<long long>&, const int&, const int&);
void calcu(long long, long long&, vector<long long>&, int, int);

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n;  cin >> n;
    vector<long long> v;
    for (int i = 0; i < n; ++i) {
        long long input;  cin >> input;
        v.push_back(input);
    }

    if (v.size() < 3) {
        cout << 0 << endl;
        return 0;
    }

    long long sum = 0;
    long long min = LLONG_MAX;
    calcu(sum, min, v, 0, v.size() - 1);

    cout << min << endl;

    return 0;
}

long long sd( vector<long long>& v, const int& l, const int& r) {

    long long midnum=0;
    priority_queue<long long> pq;
    for(int i=l;i<r+1;++i){
        pq.push(v[i]);
    }
    int n=(r-l)/2;
    while(n--){
        pq.pop();
    }
    if((r-l+1)%2!=0){
    midnum=pq.top();
    }
    else{
        midnum+=pq.top();
        pq.pop();
        midnum+=pq.top();
        midnum/=2;
// cout<<"midnum_b = "<<temp/2<<endl;
    }

    long long sd=0;
    for(int i=l;i<r+1;++i){
        sd+=abs(midnum-v[i]);
    }

    return sd;
}

void calcu(long long sum, long long& ans, vector<long long>& v, int a, int b) {
    if(sum>ans) return;
    int mid = (a + b) / 2;
    if (mid - a + 1 < 3 && b - mid < 3) {
        long long temp = sum + min(sd(v, a, mid), sd(v, mid + 1, b));
        if (temp < ans) {
            ans = temp;
        }
        return;
    }
    if (mid - a +1< 3) {
        long long temp = sum + sd(v, mid + 1, b);
        if ( temp< ans) {
            ans = temp;
        }
        return;
    }
    if (b - mid < 3) {
        long long temp = sum + sd(v, a, mid);
        if (temp < ans) {
            ans = temp;
        }
        return;
    }

    long long left = sd(v, a, mid)+sum,
        right = sd(v, mid + 1, b)+sum;

    // if(left<ans)
        calcu(left, ans, v, mid+1, b);

    // if(right<ans)
        calcu(right , ans, v, a, mid);
}