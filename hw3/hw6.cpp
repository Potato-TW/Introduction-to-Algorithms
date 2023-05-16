#include<bits/stdc++.h>
// #define long long lo
using namespace std;

int calcu(vector<vector<int>>& v){
    for(int i=0;i<v.size();++i){
        for(int j=0;j<v[0].size();++j){
            if(!i||!j){
                v[i][j]=1;
                continue;
            }
            v[i][j]=(v[i-1][j]+v[i][j-1])%100000007;
        }
    }

    return v[v.size()-1][v[0].size()-1];
}


int main(){
    int a, b;   cin>>a>>b;

    vector<vector<int>> v(a, vector<int>(b, 0));

    cout<<calcu(v);    

    return 0;
}
