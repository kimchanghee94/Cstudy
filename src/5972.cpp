#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX_N 50005
#define INF 1000000000

vector<pair<int,int>> nodes[MAX_N];
int N,M,dist[MAX_N];

int dijkstra(int strt){
    priority_queue<pair<int,int>> pq;
    pq.push({0,strt});
    dist[strt]=0;

    while(!pq.empty()){
        int fc=-pq.top().first;
        int fn=pq.top().second;
        pq.pop();
        if(dist[fn]<fc) continue;
        
        for(int i=0; i<nodes[fn].size(); i++){
            int nc=fc+nodes[fn][i].first;
            int nn=nodes[fn][i].second;
            if(nc<dist[nn]){
                dist[nn]=nc;
                pq.push({-nc,nn});
            }
        }
    }
    return dist[N-1];
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>N>>M;
    for(int i=0; i<N; i++) dist[i]=INF;
    for(int i=0; i<M; i++){
        int a,b,c; cin>>a>>b>>c;
        nodes[a-1].push_back({c,b-1});
        nodes[b-1].push_back({c,a-1});
    }
    cout<<dijkstra(0);
}