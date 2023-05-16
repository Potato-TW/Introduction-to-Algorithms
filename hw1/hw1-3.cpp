#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;

int main(){
    int n,target;  cin>>n>>target;
    vector<int> num;
    for(int i=0;i<n;i++){
        int input;  cin>>input;
        num.push_back(input);
    }
    sort(num.begin(), num.end());

    vector<vector<int>> ans;
    set<vector<int>> s;
    
    for(int i = 0;i < num.size();i++){
        for(int j = i+1;j < num.size();j++ ){
            int a = j+1;
            int b = num.size()-1;
            
            while(a<b){
                if((long)num[i]+num[j]+num[a]+num[b] > target){
                    b--;
                }
                
                else if((long)num[i]+num[j]+num[a]+num[b] < target){
                    a++;
                }
                
                else{
                    s.insert({num[i],num[j],num[a],num[b]});
                    a++;
                    b--;
                    while(a<b && num[a] == num[a-1]) a++;
                    while(a<b && num[b] == num[b+1]) b--;
                }
            }
        }
    }

    if(!s.empty())
        cout<<s.size()<<endl;
    else
        cout<<"FeiDooDoo_Zuo_Wei_Men"<<endl;
    return 0;
}