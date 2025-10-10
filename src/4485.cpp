#include <iostream>
#include <queue>
using namespace std;

#define MAX 126
#define INF MAX*MAX*10

struct pos{
    int cost,first,second;
    bool operator>(const pos &other) const{
        return cost>other.cost;
    }
};
priority_queue<pos,vector<pos>,greater<pos>> pq;
int N,graph[MAX][MAX],dist[MAX][MAX];
int di[]={1,0,-1,0},dj[]={0,1,0,-1};

void bfs(int turn){
    pq.push({graph[0][0],0,0});
    dist[0][0]=graph[0][0];

    while(!pq.empty()){
        auto [fc,fi,fj]=pq.top(); pq.pop();
        if(fc>dist[fi][fj]) continue;

        for(int d=0; d<4; d++){
            int ni=fi+di[d],nj=fj+dj[d];
            if(ni<0||nj<0||ni>=N||nj>=N) continue;
            int nc=fc+graph[ni][nj];
            if(dist[ni][nj]<=nc) continue;
            dist[ni][nj]=nc;
            pq.push({nc,ni,nj});
        }
    }
    cout<<"Problem "<<turn<<": "<<dist[N-1][N-1]<<"\n";
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int turn=1;
    while(true){
        cin>>N; if(!N) break;
        for(int i=0; i<N; i++) for(int j=0; j<N; j++) cin>>graph[i][j],dist[i][j]=INF;
        bfs(turn++);
    }
}