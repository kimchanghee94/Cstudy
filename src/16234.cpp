#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAX 51

int N,L,R,psum;
int graph[MAX][MAX],flag[MAX][MAX];
vector<pair<int,int>> v;
int di[]={1,0,-1,0},dj[]={0,1,0,-1};

void dfs(int si, int sj){
    flag[si][sj]=1;
    psum+=graph[si][sj];
    v.push_back({si,sj});
    for(int d=0; d<4; d++){
        int ni=si+di[d],nj=sj+dj[d];
        if(ni<0 || nj<0 || ni>=N || nj>=N || flag[ni][nj]) continue;
        int val=abs(graph[si][sj]-graph[ni][nj]);
        if(L<=val && val<=R) dfs(ni,nj);
    }
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>N>>L>>R;
    for(int i=0; i<N; i++) for(int j=0; j<N; j++) cin>>graph[i][j];
    int ans=0;
    while(1){
        int chk=0;
        for(int i=0; i<N; i++) for(int j=0; j<N; j++){
            if(flag[i][j]) continue;
            dfs(i,j);

            int cnt=v.size();
            while(!v.empty()){
                graph[v.back().first][v.back().second]=psum/cnt;
                v.pop_back();
            }
            if(cnt>1) chk=1;
            psum=0;
        }
        for(int i=0; i<N; i++) memset(flag[i],0,sizeof(flag[i]));
        if(!chk) break;
        ans++;
    }
    cout<<ans;
}