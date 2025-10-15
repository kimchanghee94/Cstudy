#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define MAX 1001
#define INF 200005

int N,M,X,dist[2][MAX];
vector<pair<int,int>> n[2][MAX];
priority_queue<pair<int,int>> pq;

void dijkstra(int s){
    dist[s][X]=0;
    pq.push({0,X});
    while(!pq.empty()){
        int fc=-pq.top().first;
        int si=pq.top().second;
        pq.pop();

        if(fc>dist[s][si]) continue;

        for(int i=0; i<n[s][si].size(); i++){
            int nc=n[s][si][i].first+fc;
            int ei=n[s][si][i].second;
            if(nc>=dist[s][ei]) continue;
            dist[s][ei]=nc;
            pq.push({-nc,ei});
        }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int ans=0; cin>>N>>M>>X;
    for(int i=0; i<M; i++){
        int s,e,c; cin>>s>>e>>c;
        n[0][s].push_back({c,e});
        n[1][e].push_back({c,s});
    }
    for(int i=0; i<2; i++) fill(dist[i]+1,dist[i]+N+1,INF);
    dijkstra(0),dijkstra(1);
    for(int i=1; i<=N; i++) ans=max(ans, dist[0][i]+dist[1][i]);
    cout<<ans;
}