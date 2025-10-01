#include <iostream>
#include <queue>
using namespace std;
#define MAX 1001
int N,M;
int graph[MAX][MAX];
queue<pair<int,int>> q;
int di[4]={0,1,0,-1},dj[4]={1,0,-1,0};

void bfs(){
    while(!q.empty()){
        int si=q.front().first;
        int sj=q.front().second;
        q.pop();

        for(int d=0; d<4; d++){
            int ni=si+di[d];
            int nj=sj+dj[d];
            if(ni<0 || ni>=N || nj<0 || nj>=M || graph[ni][nj]!=-1) continue;
            graph[ni][nj]=graph[si][sj]+1;
            q.push({ni,nj});
        }
    }
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>N>>M;
    for(int i=0;i<N;i++)for(int j=0;j<M;j++) {
        cin>>graph[i][j];
        if(graph[i][j]==2) graph[i][j]=0, q.push({i,j});
        else if(graph[i][j]==1) graph[i][j]=-1;
    }
    bfs();
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) cout<<graph[i][j]<<" ";
        cout<<"\n";
    }
}