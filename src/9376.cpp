#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;
#define MAX 105

int h,w,flag[3][MAX][MAX];
int di[]={1,0,-1,0},dj[]={0,1,0,-1};
char graph[MAX][MAX];

void dijkstra(int si, int sj, int cnt){
    deque<pair<int,int>> dq;
    flag[cnt][si][sj]=0;
    dq.push_front({si,sj});

    while(!dq.empty()){
        auto [fi,fj]=dq.front();
        dq.pop_front();
        int fc=flag[cnt][fi][fj];
        for(int d=0;d<4;d++){
            int ni=fi+di[d],nj=fj+dj[d], nc=fc;
            if(ni<0||ni>=h||nj<0||nj>=w||graph[ni][nj]=='*') continue;
            if(graph[ni][nj]=='#') nc++;
            if(flag[cnt][ni][nj]<=nc) continue;
            flag[cnt][ni][nj]=nc;
            if(graph[ni][nj]=='#') dq.push_back({ni,nj});
            else dq.push_front({ni,nj});
        }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin>>T;
    while(T--){
        vector<pair<int,int>> pos;
        pos.push_back({0,0});
        int ans=MAX*MAX;
        cin>>h>>w;
        h+=2,w+=2;
        for(int i=1;i<h-1;i++) cin>>graph[i];
        for(int i=1;i<h-1;i++) for(int j=w-2;j>0;j--) graph[i][j]=graph[i][j-1];
        for(int i=0;i<h;i++) graph[i][0]='.', graph[i][w-1]='.';
        for(int i=0;i<w;i++) graph[0][i]='.', graph[h-1][i]='.';
        for(int i=0;i<h;i++) for(int j=0;j<w;j++) if(graph[i][j]=='$') pos.push_back({i,j});
        for(int i=0;i<3;i++) for(int j=0;j<h;j++) fill(flag[i][j],flag[i][j]+MAX,MAX*MAX);
        for(int i=0;i<3;i++) dijkstra(pos[i].first,pos[i].second,i);

        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                if(graph[i][j]=='*') continue;
                flag[0][i][j]+=(flag[1][i][j]+flag[2][i][j]);
                if(graph[i][j]=='#') flag[0][i][j]-=2;
                ans=min(ans,flag[0][i][j]);
            }
        }
        cout<<ans<<"\n";
    }
}