#include<iostream>
#include<vector>
using namespace std;

int main(){
    long long int n, k;    cin>>n>>k;
    vector<long long int> ans(k, 1);

    int count=k-1;
    bool cond=0;    // cond=0 -> no    cond=1 -> yes
    while(1){
        if(n<k){break;}
        if(n==k){cond=1;break;}
        if(n<=0||k==0){break;}
        if(n<2*k||n%2==1){k--;n--;}
        else{
            n/=2;
            for(int i=0;i<k;i++){
                ans[i]*=2;
            }    
        }
    }

    if(cond){
        cout<<"YES"<<endl;
        for(int i=0;i<ans.size();i++){
             cout<<ans[i]<<" ";
        } 
    }
    else{
         cout<<"NO"<<endl;}

    return 0;
}

