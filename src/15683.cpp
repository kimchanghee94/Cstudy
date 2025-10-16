#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 9

int N,M,ans=MAX*MAX;
int g[MAX][MAX];
int dcnt[][2]={{0,0},{4,1},{2,2},{4,2},{4,3},{1,4}};
int dir[6][4][4][2]={
    {},
    {{{-1,0}},{{1,0}},{{0,1}},{{0,-1}}},
    {{{-1,0},{1,0}},{{0,1},{0,-1}}},
    {{{-1,0},{0,1}},{{-1,0},{0,-1}},{{1,0},{0,1}},{{1,0},{0,-1}}},
    {{{-1,0},{1,0},{0,1}},{{-1,0},{0,1},{0,-1}},{{0,-1},{1,0},{-1,0}},{{0,-1},{0,1},{1,0}}},
    {{{-1,0},{1,0},{0,1},{0,-1}}}
};
vector<pair<int,int>> cctv;

void dfs(int cnt){
    if(cnt==cctv.size()){
        int tmp_ans=0;
        for(int i=0;i<N;i++) for(int j=0;j<M;j++) if(!g[i][j]) tmp_ans++;
        ans=min(ans,tmp_ans);
    }else{
        int tmp[MAX][MAX];
        for(int i=0;i<N;i++) for(int j=0;j<M;j++) tmp[i][j]=g[i][j];
        int fi=cctv[cnt].first, fj=cctv[cnt].second;
        int cnum=g[fi][fj];
        for(int r=0;r<dcnt[cnum][0];r++){
            for(int d=0;d<dcnt[cnum][1];d++){
                int ni=fi+dir[cnum][r][d][0];
                int nj=fj+dir[cnum][r][d][1];
                while(0<=ni && ni<N && 0<=nj && nj<M && g[ni][nj]!=6){
                    if(!g[ni][nj]) g[ni][nj]=-1;
                    ni+=dir[cnum][r][d][0];
                    nj+=dir[cnum][r][d][1];
                }
            }
            dfs(cnt+1);
            for(int i=0;i<N;i++) for(int j=0;j<M;j++) g[i][j]=tmp[i][j];
        }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>N>>M;
    for(int i=0; i<N; i++) for(int j=0; j<M; j++){
        cin>>g[i][j];
        if(1<=g[i][j] && g[i][j]<=5) cctv.push_back({i,j});
    }
    dfs(0);cout<<ans;
}