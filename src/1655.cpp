#include <iostream>
#include <queue>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N; cin>>N;
    priority_queue<int> lq;
    priority_queue<int, vector<int>, greater<int>> rq;
    for(int i=0;i<N;i++){
        int V; cin>>V;
        if(lq.empty()) lq.push(V);
        else if(lq.size()==rq.size()){
            if(rq.top()<V){
                lq.push(rq.top());
                rq.pop();
                rq.push(V);
            }else lq.push(V);
        }else if(lq.size()>rq.size()){
            if(lq.top()>V){
                rq.push(lq.top());
                lq.pop();
                lq.push(V);
            }else rq.push(V);
        }
        cout<<lq.top()<<"\n";
    }
}