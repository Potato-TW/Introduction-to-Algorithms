#include<iostream>
#include<queue>
using namespace std;

int main(){
    int n;  cin>>n;
    queue<int> q;
    priority_queue<int> pq; // big to small
    for(int i=0;i<n;++i){
        int key;    cin>>key;
        if(key==1){
            int num;    cin>>num;
            q.push(num);
        }
        else if(key==2){
            while(!q.empty()){
                pq.push(q.front());
                q.pop();
            }
        }
        else{
            if(pq.empty()){
                if(q.empty()){
                    cout<<"Oh Oh"<<endl;
                }
                else{
                    cout<<q.front()<<endl;
                    q.pop();
                }
            }
            else{
                cout<<pq.top()<<endl;
                pq.pop();
            }
        }
    }
    return 0;
}