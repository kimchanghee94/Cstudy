#include <iostream>
#include <queue>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);cin.tie(0);
    priority_queue<int,vector<int>,greater<int>> q;
    int N; cin>>N;
    while(N--){
        int prom; cin>>prom;
        if(!prom) {
            if(!q.size()) cout<<0<<"\n";
            else{
                cout<<q.top()<<"\n";
                q.pop();
            }
        }
        else q.push(prom);
    }
}