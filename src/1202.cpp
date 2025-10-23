#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

#define MAX 300001

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N,K,c[MAX]; cin>>N>>K;
    long long ans=0;
    pair<int,int> j[MAX];
    priority_queue<int> pq;

    for(int i=0;i<N;i++) cin>>j[i].first>>j[i].second;
    for(int i=0;i<K;i++) cin>>c[i];
    sort(j,j+N);
    sort(c,c+K);

    int idx=0;
    for(int i=0;i<K;i++){
        while(idx<N && c[i]>=j[idx].first) pq.push(j[idx++].second);
        if(!pq.empty()){
            ans+=pq.top();
            pq.pop();
        }
    }
    cout<<ans;
}