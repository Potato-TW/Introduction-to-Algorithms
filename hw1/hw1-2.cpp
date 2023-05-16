#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
    long long int n;  cin>>n;
    priority_queue<long long int, vector<long long int>, greater<long long int>> pq;
    long long int count=0;
    for(long long int i=0;i<n;++i){
        long long int temp;   cin>>temp;
        pq.push(temp);
        if(temp<=n)  count++; 
    }

    long long int ans=1;
    long long int time=0;
    long long int re=1;
    while(!pq.empty()){
        long long int now = pq.top()-time;
        
        if(now<=0){
            cout<<0;    return 0;
        }

        if(count<=0){
            ans*=re;
            ans%=1000000007;            
            re++;
        }
        else{
            ans*=now;
ans%=1000000007;
        }
        ++time;
        pq.pop();
        count--;
    }

    cout<<ans%1000000007;

    return 0;
}