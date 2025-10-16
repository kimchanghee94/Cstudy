#include <iostream>
#include <queue>
using namespace std;
#define MAX 1002
int N,M,f[2][MAX][MAX];
char g[MAX][MAX];
int di[]={1,0,-1,0}, dj[]={0,1,0,-1};

int bfs(){
    queue<pair<int,pair<int,int>>> q;
    q.push({0,{0,0}});
    f[0][0][0]=1;

    while(!q.empty()){
        auto [b, pos]=q.front();
        auto [fi, fj]=pos;
        q.pop();
        if(fi==N-1 && fj==M-1) return f[b][N-1][M-1];
        for(int d=0;d<4;d++){
            int ni=fi+di[d],nj=fj+dj[d],nb=b;
            if(ni<0||ni>=N||nj<0||nj>=M||f[nb][ni][nj]||(nb && g[ni][nj]=='1')) continue;
            if(g[ni][nj]=='1') nb=1;
            f[nb][ni][nj]=f[b][fi][fj]+1;
            q.push({nb,{ni,nj}});
        }
    }
    return -1;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>N>>M;
    for(int i=0;i<N;i++) cin>>g[i];
    cout<<bfs();    
}