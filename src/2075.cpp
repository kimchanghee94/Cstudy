#include <iostream>
#include <queue>
using namespace std;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int N; cin>>N;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0; i<N*N; i++){
        int val; cin>>val;
        pq.push(val);
        if(pq.size()==N+1) pq.pop();
    }
    cout<<pq.top();
}