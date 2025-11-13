#include <iostream>
#include <vector>
#include <deque>
using namespace std;

#define MAX 101
int H,W,flag[MAX][MAX];
int di[]={1,0,-1,0},dj[]={0,1,0,-1};
char graph[MAX][MAX];

void bfs(int si, int sj, int ei, int ej){
    deque<pair<pair<int,int>,pair<int,int>>> dq;
    dq.push_front({{-1,0},{si,sj}});
    flag[si][sj]=0;

    while(!dq.empty()){
        int fd=dq.front().first.first;
        int fc=dq.front().first.second;
        int fi=dq.front().second.first;
        int fj=dq.front().second.second;

        dq.pop_front();
        for(int d=0;d<4;d++){
            int ni=fi+di[d],nj=fj+dj[d],nc=fc;
            if(ni<0||ni>=H||nj<0||nj>=W||graph[ni][nj]=='*') continue;
            if(fd!=-1 && fd!=d) nc++;
            if(flag[ni][nj]<nc || (fd!=d && flag[ni][nj]==nc)) continue;
            if(fd==-1 || fd==d) dq.push_front({{d,nc},{ni,nj}});
            else dq.push_back({{d,nc},{ni,nj}});
            flag[ni][nj]=nc;
        }
    }
    cout<<flag[ei][ej];
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>W>>H;
    vector<pair<int,int>> pos;
    for(int i=0;i<H;i++) for(int j=0;j<W;j++){
        cin>>graph[i][j];
        flag[i][j]=MAX*MAX;
        if(graph[i][j]=='C') pos.push_back({i,j});
    }
    bfs(pos[0].first,pos[0].second, pos[1].first, pos[1].second);
}