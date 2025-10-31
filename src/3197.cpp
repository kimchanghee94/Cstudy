#include <iostream>
#include <queue>
using namespace std;
#define MAX 1502

int R,C,ei,ej;
int di[]={1,0,-1,0},dj[]={0,1,0,-1};
char graph[MAX][MAX];
queue<pair<int,int>> q,xq;

int bfs(){
    int ans=0;
    while(1){
        queue<pair<int,int>> nq;
        while(!q.empty()){
            auto [fi,fj]=q.front();
            q.pop();
            if(fi==ei && fj==ej) return ans;
            for(int d=0;d<4;d++){
                int ni=fi+di[d],nj=fj+dj[d];
                if(ni<0||ni>=R||nj<0||nj>=C||graph[ni][nj]=='L') continue;
                if(graph[ni][nj]=='D') nq.push({ni,nj});
                if(graph[ni][nj]=='.') q.push({ni,nj});
                graph[ni][nj]='L';
            }
        }
        q=nq;
        int xq_size=xq.size();
        for(int i=0;i<xq_size;i++){
            auto [fi,fj]=xq.front();
            xq.pop();
            if(graph[fi][fj]=='D') graph[fi][fj]='.';
            for(int d=0;d<4;d++){
                int ni=fi+di[d],nj=fj+dj[d];
                if(ni<0||ni>=R||nj<0||nj>=C||graph[ni][nj]!='X') continue;
                graph[ni][nj]='D';
                xq.push({ni,nj});
            }
        }
        ans++;
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>R>>C;
    int chk=0;
    for(int i=0;i<R;i++) for(int j=0;j<C;j++) {
        cin>>graph[i][j];
        if(graph[i][j]=='L' && !chk) q.push({i,j}), chk=1;
        else if(graph[i][j]=='L') ei=i,ej=j,graph[i][j]='.';
    }
    for(int i=0;i<R;i++) for(int j=0;j<C;j++) if(graph[i][j]=='X') for(int d=0;d<4;d++){
        int ni=i+di[d],nj=j+dj[d];
        if(ni<0||ni>=R||nj<0||nj>=C||graph[ni][nj]=='X'||graph[ni][nj]=='D') continue;
        graph[i][j]='D';
        xq.push({i,j});
        break;
    }
    cout<<bfs();
}