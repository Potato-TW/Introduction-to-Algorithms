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

    // robinson-schensted-knuth algorithm 
    vector<int> pos(n, 0), templis;

    for(int i=0;i<v.size();++i){
        if(!i){
            templis.push_back(v[i]);
            pos[i]=1;
            continue;
        }   
        
        int diff=lower_bound(templis.begin(), templis.end(), v[i])-templis.begin();
        if(diff==templis.size()){
            templis.push_back(v[i]);
            pos[i]=templis.size();
        }
        else{
            templis[diff]=v[i];
            pos[i]=diff+1;
        }
        // cout<<"templis:\n";
        // for(auto j:templis) cout<<j<<" ";
        // cout<<"\npos:\n";
        // for(auto j:pos) cout<<j<<" ";
        // cout<<"\ndiff:"<<diff<<endl;
    }    

    vector<int> lis(templis.size(), 0);
    int k=templis.size()-1;
    for(int i=pos.size()-1;i>-1;--i){
        if(k==pos[i]-1){
            lis[k]=v[i];
            k--;
        }
    }
    
    cout<<lis.size()<<endl;

    return 0;
}