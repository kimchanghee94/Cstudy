#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 100001
#define INF 1ll*MAX*MAX*MAX
#define ll long long

int N,M;
vector<pair<int,int>> edge[MAX];

void dijkstra(){    
    priority_queue<pair<ll,int>> pq;
    ll dist[MAX];
    fill(dist, dist+N+1, INF);
    pq.push({0,1});
    dist[1]=0;

    while(!pq.empty()){
        int s=pq.top().second;
        ll c=-pq.top().first;
        pq.pop();

        if(dist[s]<c) continue;
        for(int i=0;i<edge[s].size();i++){
            int e=edge[s][i].second;
            ll nc=edge[s][i].first;

            if(nc<c){
                ll cycle=(c-nc)/M;
                if((c-nc)%M!=0) cycle++;
                nc=cycle*M+nc;
            }

            if(nc>=dist[e]) continue;
            dist[e]=nc;
            pq.push({-nc,e});
        }
    }
    cout<< dist[N];
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>N>>M;
    for(int i=1;i<=M;i++){
        int a,b; cin>>a>>b;
        edge[a].push_back({i,b});
        edge[b].push_back({i,a});
    }
    dijkstra();
}