#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0), cin.tie(0);

    int n;  cin>>n;
  
    vector<int> v;

    for(int i=0;i<n;++i){
        int input;  cin>>input;
        v.push_back(input);
    }        


    // - 1 -2 2 3
    // 0 1 -1 1 4
    vector<int> sum(n+1, 0);  
    int min=INT_MAX, max=INT_MIN;

    for(int i=0;i<sum.size();++i){
        if(i>0)
            sum[i]=v[i-1]+sum[i-1];

        if(sum[i]<min)
            min=sum[i];
        if(sum[i]>max)
            max=sum[i];
    }

    // cout<<"----"<<endl;<<endl
    // for(auto i:sum)
    //     cout<<i<<" ";
    // cout<<endl<<"----"<<endl;

    int diff=max-min;
    cout<<diff<<endl;


    return 0;
}